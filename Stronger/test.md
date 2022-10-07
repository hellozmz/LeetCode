# 测试环境
* 利用vscode
* 安装debug插件：CODELLDB（可选）
* 修改tasks.json
* 修改launch.json


# tasks.json
```json
{
    "tasks": [
        {
            "type": "cppbuild",
            "label": "C/C++: g++-8 生成活动文件",
            "command": "/usr/local/bin/g++-8",
            "args": [
                "-fdiagnostics-color=always",
                "-g",
                "${file}",
                "-o",
                "${fileDirname}/${fileBasenameNoExtension}"
            ],
            "options": {
                "cwd": "${fileDirname}"
            },
            "problemMatcher": [
                "$gcc"
            ],
            "group": {
                "kind": "build",
                "isDefault": true
            },
            "detail": "调试器生成的任务。"
        }
    ],
    "version": "2.0.0"
}
```

# launch.json
```json
{
    // 使用 IntelliSense 了解相关属性。 
    // 悬停以查看现有属性的描述。
    // 欲了解更多信息，请访问: https://go.microsoft.com/fwlink/?linkid=830387
    "version": "0.2.0",
    "configurations": [

        {
            "name": "调试lc代码-lldb",
            "type": "lldb",
            "request": "launch",
            "program": "${fileDirname}/${fileBasenameNoExtension}",
            "args": [],
            "cwd": "${fileDirname}",
            "preLaunchTask": "C/C++: g++-8 生成活动文件",       // 和task.json 中lable对应
        },

        {
            "name": "调试lc代码-cppdbg",
            "type": "cppdbg",
            "request": "launch",
            "program": "${fileDirname}/${fileBasenameNoExtension}",
            "args": [],
            "stopAtEntry": false,
            "cwd": "${fileDirname}",
            "environment": [],
            "externalConsole": false,
            "MIMode": "lldb",
            "preLaunchTask": "C/C++: g++-8 生成活动文件",       // 和task.json 中lable对应
        }
    ]
}
```

# 使用方法
1. 在测试代码中编写代码，并引入header.h
2. 在test.cc中引入测试代码，并构造测试用例
3. 在vscode中执行debug功能，可以进行单步调试