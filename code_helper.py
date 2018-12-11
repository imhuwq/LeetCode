import os
import sys

title = "141. Linked List Cycle"

description = """
Given a linked list, determine if it has a cycle in it.

To represent a cycle in the given linked list, we use an integer pos which represents the position (0-indexed) in the linked list where tail connects to. If pos is -1, then there is no cycle in the linked list.

 

Example 1:
Input: head = [3,2,0,-4], pos = 1
Output: true
Explanation: There is a cycle in the linked list, where tail connects to the second node.

Example 2:
Input: head = [1,2], pos = 0
Output: true
Explanation: There is a cycle in the linked list, where tail connects to the first node.

Example 3:
Input: head = [1], pos = -1
Output: false
Explanation: There is no cycle in the linked list.
 
Follow up:
Can you solve it using O(1) (i.e. constant) memory?

"""

class_body = """
    struct ListNode {
        int val;
        ListNode *next;
        ListNode(int x) : val(x), next(NULL) {}
    };
     
    class Solution {
    public:
        bool hasCycle(ListNode *head) {
            
        }
    };
"""

common_header_lines = """
#include <stack>
#include <vector>
#include <string>
#include <climits>
#include <iostream>
#include <gtest/gtest.h>

using namespace std;
"""

namespace_body_tpl = """
namespace {namespace_name} {{
{class_body}
}}
"""

unit_test_body_tpl = """
TEST({test_name}, CASE_TEST) {{
    using namespace {namespace_name};
    Solution s;
    
    EXPECT_EQ(1, 1);
}}
"""

unit_test_source_file = "UnitTest.cpp"


def generate_file_name(title_):
    order, name = title_.split(". ")
    order = order.zfill(4)
    name = name.replace(" ", "")
    return "include/{0}_{1}.h".format(order, name)


def generate_description_doc(description_):
    padding = " * "
    lines = description_.split("\n")[1:-1]
    lines = [padding + line for line in lines]
    lines.insert(0, "/*")
    lines.append(" */")
    lines.append("\n")
    doc = "\n".join(lines)
    return doc


def generate_include_guards(title_):
    order, name = title_.split(". ")
    order = order.zfill(4)
    name = name.replace(" ", "_")
    guard = "LEET_CODE_{0}_{1}_H_".format(order, name).upper()
    return ["#ifndef {0}\n".format(guard),
            "#define {0}\n".format(guard),
            "#endif //{0}\n".format(guard)]


def generate_source_code_body(title_):
    order, name = title_.split(". ")
    order = order.zfill(4)
    namespace_name = "L{0}".format(order)
    namespace_body = namespace_body_tpl.format(namespace_name=namespace_name, class_body=class_body)

    test_name = "L{0}_{1}".format(order, name).replace(" ", "_").upper()
    unit_test_body = unit_test_body_tpl.format(test_name=test_name, namespace_name=namespace_name)

    source_code_body = namespace_body + unit_test_body + "\n"
    return source_code_body


def generate_problem_template():
    file_name = generate_file_name(title)
    include_guards = generate_include_guards(title)
    description_doc = generate_description_doc(description)
    source_code_body = generate_source_code_body(title)

    if os.path.exists(file_name):
        print("File Exists, do you want to overwrite it?")
        exit(1)

    with open(file_name, "w") as f:
        f.write(description_doc)
        f.write(include_guards[0])
        f.write(include_guards[1])
        f.write(common_header_lines)
        f.write(source_code_body)
        f.write(include_guards[2])

    with open(unit_test_source_file, "a") as f:
        include_file_name = file_name.split("/")[-1]
        f.write("#include \"{0}\"\n".format(include_file_name))


def commit_problem_solution():
    solution_file = generate_file_name(title)
    os.system("git add {0}".format(solution_file))
    os.system("git add UnitTest.cpp")

    solution_title = "".join(title.split(" ")[1:])
    commit_message = "new(solution): {0}".format(solution_title)
    os.system("git commit -m \"{0}\"".format(commit_message))


if __name__ == '__main__':
    if len(sys.argv) == 1 or sys.argv[1] == "generate":
        generate_problem_template()
    elif sys.argv[1] == "commit":
        commit_problem_solution()
    else:
        print("generate or commit")
