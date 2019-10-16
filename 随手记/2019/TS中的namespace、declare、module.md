# TS中的namespace、declare、module

## 问题1: [TS中的namespace、module有什么区别？](https://stackoverflow.com/questions/41932585/what-is-the-difference-between-declare-namespace-and-declare-module)


## 问题2: [.d.ts文件和.ts文件有什么区别？](https://jkchao.github.io/typescript-book-chinese/typings/ambient.html#%E5%A3%B0%E6%98%8E%E6%96%87%E4%BB%B6)
.d.ts后缀的文件通常表示类型声明。用法：
1. 为js文件提供类型说明：js是没有类型约束的，一个js模块在ts项目中使用，无法获取js中的数据类型。这时可以在对应的js文件处增加同名的.d.ts文件，在其中描述这个js文件中的数据类型。ts项目会默认读取.d.ts文件中的类型定义。
2. 在ts项目中用全局的命名空间来定义一些interface


## 问题3: 为什么在.d.ts文件中必须用declare声明
这是个约定，.d.ts里面声明的所有东西都得用declare去声明，如果在.ts文件里面，直接写namespace也是没有问题的，编译器也是能识别的，但是.d.ts里面写namespace就报错了，必须得declare namespace。

