if [ $# -eq 2 ]
then
	if [ -d $2 ]
	then 
		echo "Directory already exist"
		exit 1
	else
		mkdir $2
		cd $2
	fi
fi
	


file=$1".cpp"
if [ -f $file ]
then
	echo "File already exist"
	exit 1
else
	touch $file
	echo "#include <iostream>" 					>> $file
	echo "#include <cstdio>" 					>> $file
	echo "#include <cstring>" 					>> $file
	echo "#include <cstdlib>" 					>> $file
	echo "#include <vector>" 					>> $file
	echo "#include <utility>" 					>> $file
	echo "#include <queue>" 					>> $file
	echo "#include <stack>" 					>> $file
	echo "#include <list>" 						>> $file
	echo "#include <algorithm>" 				>> $file
	echo "" 									>> $file
	echo "using namespace std;"					>> $file
	echo ""										>> $file
	echo "#define INF 2147483647" 				>> $file
	echo "#define LLINF 9223372036854775807" 	>> $file
	echo "#define mp make_pair"					>> $file
	echo "#define pb push_back"					>> $file
	echo ""										>> $file
	echo "typedef long long int lli;"			>> $file
	echo "typedef unsigned int uint;"			>> $file
	echo "typedef unsigned long long int ulli;"	>> $file
	echo "typedef pair<int,int> pairint;"		>> $file	
	echo ""										>> $file
	echo "#define BUF 4096"						>> $file
	echo "char ibuf[BUF];"						>> $file
	echo "int ipt = BUF;"						>> $file
 	echo ""										>> $file
	echo "int readInt()"						>> $file
	echo "{"									>> $file
    echo "\twhile (ipt < BUF && ibuf[ipt] < '0')" >> $file
    echo "\t\tipt++;"								>> $file
    echo ""	 									>> $file
    echo "\tif (ipt == BUF)"						>> $file
    echo "\t{"									>> $file
	echo "\t\tfread(ibuf, 1, BUF, stdin);"			>> $file	 
	echo "\t\tipt = 0;"								>> $file
	echo "\t\twhile (ipt < BUF && ibuf[ipt] < '0')" >> $file
	echo "\t\t\tipt++;"								>> $file
    echo "\t}"									>> $file
    echo ""										>> $file
    echo "\tint n = 0;"							>> $file
    echo "\twhile (ipt < BUF && ibuf[ipt] >= '0')">> $file
    echo "\t\tn = (n*10)+(ibuf[ipt++]-'0');"		>> $file
 	echo ""										>> $file
    echo "\tif (ipt == BUF)"						>> $file
    echo "\t{"									>> $file
	echo "\t\tfread(ibuf, 1, BUF, stdin);" 			>> $file
	echo "\t\tipt = 0;"								>> $file
	echo "\t\twhile (ipt < BUF && ibuf[ipt] >= '0')">> $file
	echo "\t\t\tn = (n*10)+(ibuf[ipt++]-'0');"		>> $file
    echo "\t}"									>> $file
    echo "\treturn n;"							>> $file
	echo "}"									>> $file
	echo "\n/********************************************************************************************/\n"										>> $file
	echo "int i,j;"								>> $file
	echo ""										>> $file
	echo "int main()"							>> $file
	echo "{\n\treturn 0;\n}"					>> $file
fi
