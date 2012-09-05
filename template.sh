file=$1".cpp"
if [ -f $file ]
then
	echo "File already exist".
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
	echo "" 									>> $file
	echo "using namespace std;"					>> $file
	echo ""										>> $file
	echo "#define INF 2147483647" 				>> $file
	echo "#define LLINF 9223372036854775807" 	>> $file
	echo "#define make_pair mp"					>> $file
	echo "#define push_back pb"					>> $file
	echo ""										>> $file
	echo "typedef long long int lli;"			>> $file
	echo "typedef unsigned int uint;"			>> $file
	echo "typedef unsigned long long int ulli;"	>> $file
	echo "typedef pair<int,int> pairint;"		>> $file	
	echo ""										>> $file
	echo "int i,j;"								>> $file
	echo ""										>> $file
	echo "int main()"							>> $file
	echo "{\n\treturn 0;\n}"					>> $file
fi
