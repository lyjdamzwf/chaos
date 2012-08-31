##
# yunjie -
# 用法: sh op_lvl.sh O2 O0  --将chaos编译优化选项从O2改为O0

ori_op_lvl=$1
new_op_lvl=$2


echo "optimizing level:"$ori_op_lvl" >> "$new_op_lvl

seq_str="s/"$ori_op_lvl"/"$new_op_lvl"/g"
echo "seq_str:"$seq_str
find . -name "*.am" | xargs sed -i "$seq_str"

