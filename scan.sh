actual=`du $1 | awk '{ print $1 }'`; 
apparent=`du --apparent-size $1 | awk '{ print $1 }'`; 
if [ "$actual" -lt "$apparent" ] ; 
then echo `hostname` actual=$actual apparent=$apparent $1 ` ./scan < $1 > /dev/null`; 
fi
