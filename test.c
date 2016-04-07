#test script

cd /home/ltang
mkdir git
cd git
git clone git@github.com:ltang-xt/C.git
vim test.c
#git remote
git add test.c
git commit -m "modify add test.c"
git push -u origin master
