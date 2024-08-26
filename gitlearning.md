# 配置用户名及邮箱

```
git config --global user.name  "chen"

git config --global user.email 3207248497@qq.com

git config --global credential.helper store(保存密码)
```

![image-20240824153703178](C:\Users\要吃小龙虾\AppData\Roaming\Typora\typora-user-images\image-20240824153703178.png)

​        system一般不用

# 建仓库

`mkdir learn-git（创建了一个叫learn-git的目录）`

在进入该目录即cd 。。。。后创建仓库

```
1. git init  ——直接在这里面创建一个仓库

​      git init my—repo 在该目录下创建叫my—repo的仓库（使用需先cd进去）

2. git clone 地址（克隆仓库上来）
```

# git的工作区域和文件状态

![image-20240824160113572](C:\Users\要吃小龙虾\AppData\Roaming\Typora\typora-user-images\image-20240824160113572.png)

![image-20240824160655352](C:\Users\要吃小龙虾\AppData\Roaming\Typora\typora-user-images\image-20240824160655352.png)



# 添加和提交文件

```
git status ——查看仓库状态

git add 文件名 ——添加到暂存区

git commit -m“此次提交的注释信息”——提交（只提交暂存区中的内容）

git log ——查看历史提交记录
```

# git回退版本

```
git reset ——soft（回退到某一版本，但保留工作区和暂存区的内容）

git reset ——hard（回退到某一版本，但丢弃工作区和暂存区的内容）

git reset ——mixed（回退到某一版本，只保留工作区的内容，丢弃暂存区的）
```

![image-20240824165837588](C:\Users\要吃小龙虾\AppData\Roaming\Typora\typora-user-images\image-20240824165837588.png)

# 查看文件不同版本之间的差异

```
git diff（后不加参数默认比较工作区与暂存区之间的差别）

git diff head比较工作区和版本库，git diff ——cached比较暂存库和版本库
```

可以比较两个不同的版本：在后面加两个比较版本的版本号，当前版本可用Head代替，上一版本Head~，Head~2上两个版本

# 文件删除

```
git rm 文件名（ps：删除后要提交，否则删除的文件在版本库中任存在）

git rm --cached 文件名（把文件从暂存区中删除，但保留在当前工作区）

git rm -r* （递归删除某个目录下的所有子目录和文件）
```

# gitignore

创建一个.gitignore文件，在文件中写需要忽略的文件，则提交时不会提交这些上去

![image-20240824212742150](C:\Users\要吃小龙虾\AppData\Roaming\Typora\typora-user-images\image-20240824212742150.png)

# 本地与远程仓库的链接

```
https——把本地代码放入远程仓库时需验证用户名和密码

ssh——不用验证用户名和密码，但需要在gitup上添加公钥的配置（推荐）
```

# 合并分支

   分支名加序号命名文件，分支名加冒号加序号提交编写记录

```
  git banch查看仓库中所有分支，

   git banch 分支名 ——创建一个新分支（这个分支的内容基于当前主分支的内容copy一份）

   git checkout 分支名 ——切换到该分支上

   git switch 分支名 ——一样效果

   git mergr 将被合并分支名 ——注意合并后被合并分支并不会消失，当前所在分支为目标和并分支（合并后会自动产生一次提交）
```

   ![image-20240825145750091](C:\Users\要吃小龙虾\AppData\Roaming\Typora\typora-user-images\image-20240825145750091.png)

```
git log ——可查看分支图

   ps：合并有冲突时要自己去查看冲突内容并修改

   git rebase main（此时一般在dev分支里面进行操作）——使分支合并在主分支中，不再有额外分支，即两个分支合并为一条线
```



   ![image-20240825145711753](C:\Users\要吃小龙虾\AppData\Roaming\Typora\typora-user-images\image-20240825145711753.png)

   Merge不会破坏原分支的提交历史，方便回溯和查看，但会产生额外的提交节点，分支图较复杂

   Rebase不会新增额外提交记录，形成线性历史，比较直观和干净，但会待变提交历史和分支节点，应该避免在共享分支时使用

* merge分支在多人合作编写代码时使用，可以方便查看代码变化情况，便于找到修改人及修改情况，回溯历史版本

* rebase分支最好自己一个人修改代码时使用，可以使代码更简洁直观，便于提交上去与主分支合并

   rebase在gitflow流工作中多使用在feature分支的更新中，使feature分支为线性的分支，使其合并回develop分支中更加简洁，没有多余的合并提交。

# gitflow工作流程

团队成员在主分支中分离出自己的分支进行开发和改写，并在本地分支提交代码，在开发结束后，发起PR，团队成员对代码进行评估后，将其合并在主分支中