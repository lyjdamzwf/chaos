full_kernel_version=$(uname -r)
echo $full_kernel_version

fir_v=$(echo $full_kernel_version|awk -F"." '{print $1}')
sec_v=$(echo $full_kernel_version|awk -F"." '{print $2}')
suffix=$(echo $full_kernel_version|awk -F"." '{print $3}')
thi_v=$(echo $suffix|awk -F"-" '{print $1}')
#echo $fir_v
#echo $sec_v
#echo $thi_v

fir_v_def='AC_DEFINE([KER_V1],['$fir_v'],[the first kernel version])'
sec_v_def='AC_DEFINE([KER_V2],['$sec_v'],[the second kernel version])'
thi_v_def='AC_DEFINE([KER_V3],['$thi_v'],[the third kernel version])'

sed -i '-e /KER_V1/d' ./configure.ac
sed -i '-e /KER_V2/d' ./configure.ac
sed -i '-e /KER_V3/d' ./configure.ac
sed -i '-e /AC_OUTPUT/d' ./configure.ac

echo $fir_v_def >> configure.ac
echo $sec_v_def >> configure.ac
echo $thi_v_def >> configure.ac
echo 'AC_OUTPUT' >> configure.ac
