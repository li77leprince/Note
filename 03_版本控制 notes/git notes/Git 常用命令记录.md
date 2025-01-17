# Git 常用命令笔录
## Git 配置

	git config --global user.name "AlvinMi"
	git config --global user.email "alvin.mi0620@gmail.com"
	git config --global color.ui true # 打开 Git 的 color 颜色设定，这样 Git 指令的输出结果就会加上颜色，像是 git status 等。
	git config --global core.editor "vim" # 设置自己的 Editor 使用 vim
	git config --global core.quotepath false # 设置显示中文文件名
	git config --global alias.co checkout	# 别名, 参考gitbook 
	git config --global alias.ci commit
	git config --global alias.st status
	git config --global alias.br branch

使用别名配置一下, 就可以用 `st` 代替 `status` 了。

## Git 常用命令

	git help <command>  # 显示 command 的 help
	git show 		    # 显示某次提交的内容
	git show $id	

	git co --<file>	    # 抛弃工作区修改. co = checkout 
	git co .			# 

	git add <file>		# 将工作文件修改提交到本地暂存区
	git add .			# 将所有修改过的工作文件提交到暂存区

	git rm <file>		# 从版本库中删除文件
	git rm <file> --cached 	# 从版本库中文件, 但不文件

	git reset <file>	# 从暂存区恢复到工作文件
	git reset -- . 		# 从暂存区恢复到工作文件
	git reset --hard	# 恢复最近一次提交过的状态, 即放弃上次提交后的所有修改

	git ci <file>		# ci = commit
	git ci .
	git ci -a			# 将 git add、git rm 和 git ci 等操作都合并在一起做
	git ci -am "some comments"
	git ci --amend 		# 修改最后一次提交记录

	git revert <$id>	# 恢复某次提交的状态, 恢复动作本身也创建了一次提交对象
	git revert HEAD 	# 恢复最后一次提交的状态


### 查看文件 diff

	git diff <file>		# 比较当前文件和暂存区文件差异 
	git diff <$id1> <$id2>	# 比较两次提交之间的差异
	git diff <branch1>..<branch2>	# 在两个分支之间比较
	git diff --staged	# 比较暂存区和版本库差异
	git diff --cached 	# 比较暂存区和版本库差异
	git diff --stat		# 仅仅比较统计信息

### 查看提交记录

	git log
	git log <file>		# 查看这个文件每次提交的记录
	git log -p <file> 	# 查看每次详细修改内容的 diff 
	git log -p -2		# 查看最近两次详情


## Git 本地分支管理

	git br -r			# 查看远程分支
	git br <new_branch> # 创建新的分支
	git br -v			# 查看各个分支最后提交信息
	git br --merged		# 查看已经被合并到当前分支的分支
	git br --no-merged	# 查看尚未被合并到当前分支的分支

	git co <branch>		# 切换到某个分支
	git co -b <new_branch>	# 创建新的分支, 并切换到新的 new_branch
	git co -b <new_branch> <branch>	# 基于 branch 创建新的 new_branch

	git co $id			# 把某次历史提交记录 checkout 出来, 但无分支信息, 切换到其他分支会自动删除
	git co $id -b <new_branch>	# 把某次历史记录 checkout 出来, 创建一个分支

	git br -d <branch>	# 删除某个分支
	git br -D <branch>	# 强制删除某个分支(未被合并的分支被删除的时候需要强制)

### 分支合并和 rebase

	git merge <branch>	# 将 branch 分支合并到当前分支
	git merge oringin/master --no-ff	# 不要 Fast-Foward 合并, 这样可以生成 merge 提交

	git rebase master <branch>	# 将 master rebase 到 branch, 相当于：
	git co <branch> && git rebase master && git co master && git merge <branch>

### Git 暂存管理

	git stash                       # 暂存
	git stash list                  # 列所有stash
	git stash apply                 # 恢复暂存的内容
	git stash drop                  # 删除暂存区
	git stash clear					

### Git 远程分支管理

	git pull                         # 抓取远程仓库所有分支更新并合并到本地
	git pull --no-ff                 # 抓取远程仓库所有分支更新并合并到本地，不要快进合并
	git fetch origin                 # 抓取远程仓库更新
	git merge origin/master          # 将远程主分支合并到本地当前分支
	git co --track origin/branch     # 跟踪某个远程分支创建相应的本地分支
	git co -b <local_branch> origin/<remote_branch>  # 基于远程分支创建本地分支，功能同上

	git push                         # push所有分支
	git push origin master           # 将本地主分支推到远程主分支
	git push -u origin master        # 将本地主分支推到远程(如无远程主分支则创建，用于初始化远程仓库)
	git push origin <local_branch>   # 创建远程分支， origin是远程仓库名
	git push origin <local_branch>:<remote_branch>  # 创建远程分支
	git push origin :<remote_branch>  #先删除本地分支(git br -d <branch>)，然后再push删除远程分支

### Git 远程仓库管理
	
	git remote -v                    # 查看远程服务器地址和仓库名称
	git remote show origin           # 查看远程服务器仓库状态
	git remote add origin git@github:stormzhang/demo.git         # 添加远程仓库地址
	git remote set-url origin git@github.com:stormzhang/demo.git # 设置远程仓库地址(用于修改远程仓库地址

	使用命令设置跟踪远程库和本地库

	git branch --set-upstream master origin/master
	git branch --set-upstream develop origin/develop



> Git 命令参考 [阮一峰的网络日志 -- 常用 Git 命令清单](http://www.ruanyifeng.com/blog/2015/12/git-cheat-sheet.html)