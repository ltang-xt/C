#test script

step1: login 
ssh -T git@github.com

step2: add source code and check in local depot and push to github

cd /home/ltang
mkdir git
cd git
git clone git@github.com:ltang-xt/C.git
vim test.c
#git remote
git add test.c
git commit -m "modify add test.c"
git push -u origin master

######################################
git clone https://github.com/ltang-xt/C.git
