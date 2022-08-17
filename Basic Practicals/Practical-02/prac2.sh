<<com
ls
pwd
date
cal

echo "RUNNIG THE C-FILE"
read n
gcc $0
./a.out
com
echo "Enter Text for File 1"
cat > xyz
echo "Enter Text for File 2"
cat > xyz1
cat xyz1 >> xyz
echo "Displaying Concatinated File"
cat xyz
