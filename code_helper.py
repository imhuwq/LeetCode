# /usr/bin/python3

import os

title = "27. Remove Element"

description = """
Given an array nums and a value val, remove all instances of that value in-place and return the new length.

Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.

The order of elements can be changed. It doesn't matter what you leave beyond the new length.

Example 1:
Given nums = [3,2,2,3], val = 3,
Your function should return length = 2, with the first two elements of nums being 2.
It doesn't matter what you leave beyond the returned length.

Example 2:
Given nums = [0,1,2,2,3,0,4,2], val = 2,
Your function should return length = 5, with the first five elements of nums containing 0, 1, 3, 0, and 4.
Note that the order of those five elements can be arbitrary.
It doesn't matter what values are set beyond the returned length.
"""

class_body = """
    class Solution {
    public:
        int removeElement(vector<int>& nums, int val) {
            
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


if __name__ == '__main__':
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
