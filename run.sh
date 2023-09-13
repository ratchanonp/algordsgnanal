# Compile file from input path

# Get input path
input_path=$1
file_name=$(basename $input_path)

# Output path = input path + file name without extension
output_path="${input_path%.*}"

# Compile file
g++-13 --std=c++17 -Wno-psabi -o $output_path $input_path

# Get test case directory path
test_case_dir_path=$2

# Sort test case files
test_case_dir_path=$(echo $test_case_dir_path/* | tr " " "\n" | sort -V | tr "\n" " ")

# Run test cases
for test_case_path in $test_case_dir_path; do
    echo "Running test case: $test_case_path"

    LAB=$(echo $test_case_path | cut -d'/' -f2)
    TEST_CASE=$(basename $test_case_path)

    mkdir -p "$LAB/output"

    output_file_path="$LAB/output/$TEST_CASE"
    $output_path < $test_case_path > $output_file_path

done