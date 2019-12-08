# Laboration 2

## Environment & Tools
Operating system: Windows 10 Pro.

IDE: JetBrains Clion

Compiler: CMake

Git: GitBash version 2.24.0.windows.2

## Purpose
Use string manipulation to decrypt password using ROT7 and ROT9 encryption.

## Procedures
The `authenticateUser(..)` returns true or false on the authentication. 
First find the password part in the string containing username and password. 
This is done first by find the position of first ',' in the string since username doesn't containing those characters.
I chose to add a variable where the position of the ',' + 1 is stored and use that variable as start value for the loop. 
This makes that there is no need of loop through the part of the string containing the username. 
In the loop, a new string created, containing only the password. That variable has the same name as the param for decryptPassword(..) to make it easier to follow the flow.

The `decryptPassword(..)` returns a new encrypted string.
The flow is: 
There's one head loop iterates through the param: pass. In the loop there's a check if the iteration is an even number `if (i % 2 == 0)` or not `if (i % 2 == 1)`. 
The content of both if-statements differ only in the use ot ROT7 or ROT9. 
Inside the if-statements the `isVowel = false;` set. After that there's a modified for-loop `for (auto ch :VOWELS) {...}` that works like a foreach - loop.
Inside that loop there's a check against `VOWELS` if the character is a vowel. If true, the  `isVowel = true;` is set and used in a if-statement witch add the character as a consonant (without the '0' on each side of the character).

The encrypted password is returned to `authenticateUser(..)` and immediately validated and returns true or false without use of staging variables.
 
## Discussion
There were some issues during the work. First of all I started to write code before I actually knew exactly what was supposed to came out of it.
This was because I used one method for checking if I got the configuration of default variables right. When that worked, I've forgot there were only temporary. 
And that code where based on a test case and therefor the continuation on that got all wrong. 

When that issue was corrected the next was to loop through the `VOWEL` and append the content based on those conditions but omit the consonants during that loop. 
First I had a `break;` to break the iterations if a vowel was found. That gave wrong output. 
Then I moved the `decrypted.append(..)` outside the  `for (auto ch :VOWELS)` but that approached only worked in the first if-statement (to checking if it's a even or odd number on the iteration).
Eventually I added a  `bool isVowel;` that sets to true inside the   
` if (pass[i] == ch)`.

That there was some existing code in the project from start was both helpful and not.  
To get some code made it a bit easier to understand what to do, but on the other hand I'd to understand what that code actually did before start fiddling around it.

I think I pushed to origin more frequent in this laboratory, but I still have some issues to know how often one should push and when it's just overexerted.