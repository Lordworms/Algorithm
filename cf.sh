#! /bin/zsh
dir_name=$1
gang='/'
suffix=".cpp"
base_dir_name="CodeForce/"
base_dir_name=$base_dir_name$dir_name
printf "full path is  %s\n" $base_dir_name
mkdir $base_dir_name
problem_list=(
    A B C D E F
)
for var in ${problem_list[@]}
do touch $base_dir_name$gang$var$suffix
done
