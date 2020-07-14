# Regex Engine

Built a simple regex engine in Julia.

Functionality
- Has search (`searchReg`) and match (`matchReg`) functions
- Supports wildcards like `*,?,.,^,$,+!`

| WildCard | Meaning |
| --------------- | --------------- |
| _* | Zero or More of _ |
| _? | Zero or One of _  |
| .  | Any character     |
| ^  | Start of string   |
| $  | End of string     |     
| _+ | One or more of _  |
| !  | Makes wildcards unwildcardy |


Based on this [blog post](https://nickdrane.com/build-your-own-regex/)