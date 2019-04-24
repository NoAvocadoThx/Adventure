# Adventure

text based adventure game.

# How to set up
In visual studio 2017, use nuGet package manger to search and install "glm".
Use debug Win32 to build.

# How to run
In adventure/Debug/, open server.exe to initialize server. Under same folder, open adventure.exe to initialize client. 

# How to play
In adventure.exe first enter your name and follow the instruction to play.

# Current issue
'say' and 'tell' functionality still need implemention.

# Things to consider
When there are 100+ clients, command like 'pickup <item>' will rise a race condition. When multiple clients entered 'pickup <item>' command, <item> become a resource that multiple clients want to get. To solve this, we need critical region to solve this. That is, no 2 clients can use 'pickup' command at the same time and no clients should be prevented to enter critical region in a long time.
Also, race condition can be rised when those clients enter commands at the same time. To solve this, we can use apache that has MPM, a multi-processing module. Apache can distribute any thread or process to handle multiple connection and those threads/process can run on their own resources without any blocking.
  
Problems like lagging, failed to connect to server, extremely long wait time including sending to server and receiving from server 
can happen when number of users start to scale up.
 
 When user starts interacting with multiple monsters at once, multi threads are used. However, the order of interaction result might be changed. Also, if there are monsters share a same name, it is hard to tell which monster the user is trying to interact with.
 
  
  

