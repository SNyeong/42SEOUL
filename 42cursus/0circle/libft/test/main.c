#include "libft.h"
#include <stdio.h>
#include <ctype.h>

int main(void)
{
	char **s;
	char *s1 = "          ";
	
	s = ft_split(s1, ' ');
	

	// s = ft_split(s1, s2);
	// while (s[c])
	// {
	// 	printf("----%s\n", s[c]);
	// 	++c;
	// }
	// printf("----%s\n", s[c]);
	
	return (0);
}



// {
//     "version": "2.0.0",
//     "runner": "terminal",
//     "type": "shell",
//     "echoCommand": true,
//     "presentation": {
//         "reveal": "always"
//     },
//     "tasks": [
//         {
//             "label": "save and compile for C++",
//             "command": "g++",
//             "args": [
//                 "${file}",
//                 "-std=c++11",
//                 "-o",
//                 "${fileDirname}/${fileBasenameNoExtension}"
//             ],
//             "group": "build",
//             "problemMatcher": {
//                 "fileLocation": [
//                     "relative",
//                     "${workspaceRoot}"
//                 ],
//                 "pattern": {
//                     "regexp": "^(.*):(\\d+):(\\d+):\\s+(warning error):\\s+(.*)$",
//                     "file": 1,
//                     "line": 2,
//                     "column": 3,
//                     "severity": 4,
//                     "message": 5
//                 }
//             }
//         },
//         {
//             "label": "save and compile for C",
//             "command": "gcc",
//             "args": [
// 				"-g",
//                 "*.c",
//                 "-o",
//                 "${fileDirname}/${fileBasenameNoExtension}"
//             ],
//             "group": "build",
//             "problemMatcher": {
//                 "fileLocation": [
//                     "relative",
//                     "${workspaceRoot}"
//                 ],
//                 "pattern": {
//                     "regexp": "^(.*):(\\d+):(\\d+):\\s+(warning error):\\s+(.*)$",
//                     "file": 1,
//                     "line": 2,
//                     "column": 3,
//                     "severity": 4,
//                     "message": 5
//                 }
//             }
//         },
//         {
//             "label": "execute",
//             "command": "cd ${fileDirname} && ./${fileBasenameNoExtension}",
//             "group": "test"
//         },
//         {
//             "type": "shell",
//             "label": "gcc build active file",
//             "command": "/usr/bin/gcc",
//             "args": [
//                 "-g",
//                 "${file}",
//                 "-o",
//                 "${fileDirname}/${fileBasenameNoExtension}"
//             ],
//             "options": {
//                 "cwd": "/usr/bin"
//             }
//         }
//     ]
// }