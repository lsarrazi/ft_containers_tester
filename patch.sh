
output_file=$1
IFS='/' read -r -a array <<< $1

# PATCH '#include <>'
includes="${array[2]}"

sed -i -E 's/#include\s*<('$includes')>/#include "\1.hpp"/g' $output_file

# PATCH 'std::' to 'ft::''
sed -i -E 's/std\s*::\s*('$includes')/ft::\1/g' $output_file