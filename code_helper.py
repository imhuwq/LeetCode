import os
import sys

title = "35. Search Insert Position"

description = """
Given a sorted array and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

You may assume no duplicates in the array.

Example 1:
Input: [1,3,5,6], 5
Output: 2

Example 2:
Input: [1,3,5,6], 2
Output: 1

Example 3:
Input: [1,3,5,6], 7
Output: 4

Example 4:
Input: [1,3,5,6], 0
Output: 0
"""

class_body = """
    class Solution {
    public:
        int searchInsert(vector<int>& nums, int target) {
            
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
    {namespace_name}::Solution s;
    
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
    lines = description_.strip("\\n").split("\n")[1:-2]
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
