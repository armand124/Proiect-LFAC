# Constructor Implementation & Fix Walkthrough

## 1. Syntax Update: `constr` Keyword
**File:** `sintaxa.l`
- **Change:** Added the `constr` token definition.
- **Why:** To allow the lexer to recognize the new `define constr ClassName()` syntax requested.

## 2. Parser Logic & Grammar
**File:** `parser.ypp`

### A. Constructor Declaration
- **New Rule:** `constructor_decl` added to the `class_body` options.
- **Logic:**
  - Matches syntax: `define constr ID (...) { ... }`
  - **Validation:** Enforces that the constructor name (ID) matches the Class name it is defined in.
  - **Symbol Table:** Registers the symbol with category `"constructor"` and type `"VOID"` (as requested).
  - **Scoping:** Creates a new scope for the constructor body so parameters and local variables are contained.

### B. Constructor Invocation (`func_call`)
- **Logic Update:** When a function call syntax `ID(...)` is encountered:
  1. It first checks if the `ID` is a newly defined variable/function.
  2. If the `ID` refers to a **Class** (e.g., `A` in `A()`), it switches to "Constructor Mode".
  3. It performs a lookup inside that Class's symbol table to find the specific "constructor" entry.
  4. **Validation:** Checks if parameters passed match the constructor's definition.
  5. **Return Type:** Sets the return type of the expression to the Class Name (e.g., type `A`).

### C. The Segmentation Fault Fix (Critical)
- **The Problem:** Previously, the grammar rule for `func_call` was defined to return a `std::string*` (just the type name). Consequently, in the `expression` block, the rule was `| func_call {$$ = nullptr;}`.
- **The Crash:** When parsing an assignment like `oba = A();`, the parser attempted to check types: `if(id_info -> type != $3 -> get_type())`. Since `$3` (the right-hand side) was `nullptr`, calling `get_type()` on it caused the Segmentation Fault.
- **The Fix:**
  - Changed `%type` of `func_call` from `<Str>` to `<node>` (ASTnode*).
  - Updated `func_call` to create and return a valid `ASTnode` containing the return type info.
  - Updated the `expression` rule to forward this node (`$$ = $1`) instead of setting it to `nullptr`.

## 3. Input Update
**File:** `inputOK.txt`
- Updated the test file to use the new syntax: `define func A` → `define constr A()`.
