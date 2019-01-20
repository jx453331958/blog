---
title: ReactNative基础列表组件
date: 2018-12-20 09:33:02
tags:
---

@(文章)

# ReactNative常用列表组件

## ScrollView

> ScrollView是ReactNative提供的基础列表组件，非惰性渲染列表，会一次性渲染出列表中的所有元素。

**常用属性**
- onScroll: 滚动过程中的回调函数；
- scrollEventThrottle: 调用onScroll回调的频率，默认16；
- onScrollBeginDrag: 开始滚动时的回调；
- onScrollEndDrag: 结束滚动时的回调；
- refreshControl: 实现下拉刷新功能；
- showsHorizontalScrollIndicator: 是否显示水平方向的滚动条，默认true；
- showsVerticalScrollIndicator: 是否显示垂直方向的滚动条，默认true；
- stickyHeaderIndices: 指定吸顶的元素，在滚动到该元素的位置时，该元素会吸附在ScrollView头部；
- horizontal: 是否为水平滚动，默认false；
- 


**常见问题**

## FlatList

## SectionList

## VirtualizedList

## RecyclerListView

# 无限下拉场景参数调优

# 各列表使用场景汇总