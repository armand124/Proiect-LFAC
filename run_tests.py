import subprocess
import os
import sys

# Define colors for output
GREEN = '\033[92m'
RED = '\033[91m'
RESET = '\033[0m'

test_cases = [
    {
        "name": "Basic Types and Assignment",
        "code": """
        define INT i;
        define FLOAT f;
        define STR s;
        define BOOL b;
        main {
            i = 42;
            f = 3.14;
            s = "hello";
            b = 1; # integer 1 treated as true/bool
        }
        """,
        "should_pass": True
    },
    {
        "name": "Arithmetic Operations",
        "code": """
        define INT x;
        main {
            x = 10 + 5 * 2;
            Print(x == 20);
        }
        """,
        "should_pass": True,
        "expected_output": "1"
    },
    {
        "name": "Control Flow - If",
        "code": """
        define INT x;
        main {
            x = 10;
            if x > 5 then {
                Print(1);
            }
        }
        """,
        "should_pass": True,
        "expected_output": "1"
    },
    {
        "name": "Control Flow - While",
        "code": """
        define INT i;
        main {
            i = 0;
            while i < 3 {
                Print(i);
                i = i + 1;
            }
        }
        """,
        "should_pass": True,
        "expected_output": "0"
    },
    {
        "name": "Functions",
        "code": """
        define func INT add(INT $a, INT $b) {
            return $a + $b;
        }
        define INT res;
        main {
            res = add(5, 7);
            Print(res);
        }
        """,
        "should_pass": True,
        "expected_output": "0"
    },
    {
        "name": "Class Definition and Usage",
        "code": """
        define class Point {
            define INT x;
            define INT y;
            define func INT set(INT $a, INT $b) {
                x = $a;
                y = $b;
                return 0;
            }
            define func INT sum() {
                return x + y;
            }
        }
        define Point p;
        define INT s;
        main {
            p.set(10, 20);
            s = p.sum();
            Print(s);
        }
        """,
        "should_pass": True,
        "expected_output": "0"
    },
    {
        "name": "Local Scope Rules (Positive)",
        "code": """
        define func INT foo() {
            define INT local;
            local = 10;
            return local;
        }
        main {
            foo();
        }
        """,
        "should_pass": True
    },
    {
        "name": "Scope Constraint - Main Block Declaration (Negative)",
        "code": """
        main {
            define INT fail;
        }
        """,
        "should_pass": False
    },
    {
        "name": "Scope Constraint - If Block Declaration (Negative)",
        "code": """
        main {
            if 1 then {
                define INT fail;
            }
        }
        """,
        "should_pass": False
    },
    {
        "name": "Type Mismatch (Negative)",
        "code": """
        define INT i;
        define STR s;
        main {
            i = 10;
            s = "hello";
            i = i + s;
        }
        """,
        "should_pass": False
    },
    {
        "name": "Logic Operators",
        "code": """
        define BOOL b;
        main {
            b = (1 < 2) AND (3 > 1);
            Print(b);
        }
        """,
        "should_pass": True,
        "expected_output": "1" 
    },
    {
        "name": "Concatation",
        "code": """
        define STR s;
        main {
            s = "hello" + " " + "world";
            Print(s);
        }
        """,
        "should_pass": True,
        "expected_output": "hello world" 
    },
]

def run_tests():
    # 1. Compile
    print("Compiling interpreter...")
    compile_cmd = "sh compiler.sh"
    try:
        subprocess.check_call(compile_cmd, shell=True, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
        print(f"{GREEN}Compilation successful{RESET}")
    except subprocess.CalledProcessError:
        print(f"{RED}Compilation failed{RESET}")
        sys.exit(1)

    passed = 0
    total = len(test_cases)

    for test in test_cases:
        print(f"Running test: {test['name']}...", end=" ")
        
        with open("temp_test.txt", "w") as f:
            f.write(test["code"])
        
        try:
            # Run interpreter
            result = subprocess.run(
                "./interpreter < temp_test.txt",
                shell=True,
                capture_output=True,
                text=True
            )
            
            output = result.stdout.strip()
            success = (result.returncode == 0)
            
            if test["should_pass"]:
                if not success:
                    print(f"{RED}FAILED (Crash/Error){RESET}")
                    print(f"Stderr: {result.stderr}")
                else:
                    if "expected_output" in test:
                        actual_lines = [line for line in output.split('\n') 
                                      if line != "Parsing successful!" 
                                      and line != "Symbol tables written to tables.txt"]
                        actual_output = "\n".join(actual_lines).strip()
                        
                        if actual_output == test["expected_output"].strip():
                            print(f"{GREEN}PASSED{RESET}")
                            passed += 1
                        else:
                            print(f"{RED}FAILED (Output Mismatch){RESET}")
                            print(f"Expected:\n{test['expected_output']}")
                            print(f"Got:\n[{actual_output}]")
                    else:
                        print(f"{GREEN}PASSED{RESET}")
                        passed += 1
            else:
                if not success:
                    print(f"{GREEN}PASSED (Correctly Failed){RESET}")
                    passed += 1
                else:
                    print(f"{RED}FAILED (Unexpected Success){RESET}")

        except Exception as e:
            print(f"{RED}FAILED (Exception: {e}){RESET}")
            
    print(f"\nSummary: {passed}/{total} tests passed.")
    
    # Cleanup
    if os.path.exists("temp_test.txt"):
        os.remove("temp_test.txt")

if __name__ == "__main__":
    run_tests()
