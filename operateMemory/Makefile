all:read write
read:read.cpp 
	g++ read.cpp -o read -std=c++11
	@echo read程序已经生成 
write:write.cpp
	g++ write.cpp -o write -std=c++11
	@echo write程序已经生成
.PHONY:clean
clean:
	-rm read write
