输入格式：
date: YYYY-MM-DD
content: any content here.
由于内部map基于字典序的排序方法，事件格式需要一致才能正确地排序，我用一个正则表达式来对输入的date的格式进行检查，后面所有的date输入都会有这个检查

make进行编译后

pd_add使用方法：
执行下述指令就可以进行日记的写入了
./pd_add YYYY-MM-DD

pd_list使用方法：
列出所有的日记
./pd_list
列出指定时间段内的日记(时间格式要保持一致)
./pd_list YYYY-MM-DD YYYY-MM-DD

pd_show使用方法：
同样对格式会有要求，如果参数输入的个数不对的话会异常终止
./pd_show YYYY-MM-DD
