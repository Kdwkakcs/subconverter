#将subconveter编译为静态库，然后在golang中调用

## 编译为静态库
```bash
cd scripts
bash build.alpine.library.sh
```
将会编译生成libsubconveter.a静态库文件

## golang中调用
### 注意：目前仅仅支持将其他类型的订阅文件转换为singbox的格式，支持所有singbox可以转换的格式
golang 使用cgo进行golang和c之间的调用，使用`NodeToSingbox（conversion.cpp）`中的函数进行转换，现仅支持导入为Singbox。
```bash
cd test
cp libsubconveter.a ./
go run main.go
```

本项目仅供技术交流学习，严禁用于其他用途，否则后果自负。
