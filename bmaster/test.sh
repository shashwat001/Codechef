max=2
for i in `seq 2 $max`
do
    k=$(./generator >out.txt)
	l=./a.out <out.txt
done
