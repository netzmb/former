#!/bin/sh
#
# script for fix bullet path to default in irrBullet sources
#
# tested on irrBulletSDK-0.1.8
#

fixes="s/Bullet\///g;\
s/btDynamicsCommon\.h/btBulletDynamicsCommon\.h/g;\
s/irrBullet\.h/irrbullet\.h/g"


for i in $(find ./ -name *.h -or -name *.cpp);
do sed $fixes $i > $i.include-fixed && mv $i.include-fixed $i
done



