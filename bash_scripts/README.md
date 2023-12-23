# CRON-JOBS:
```crontab -e``` <br>
This command opens the CRON-EDITOR in which we need to add the specific date-time-path

```man cron```<br>
```man crontab```<br>
These commands will help into knowning the basic format for writing into the CRON-EDITOR and how the CRON-JOB works

# NEW-USER:
```sudo useradd (username)```<br>
This command help to add a new username to my system with privileges less than or equal to mine(root)

```sudo userdel -r (username)```<br>
This command helps to delete all the details from my /etc/passwd file and also deletes the directory from /home

```rm -rf (username)```<br>
[Note: when using userdel (-r) flag is neccesary and without which, we may need to remove the /home/(username) manually]<br>

# GROUPS:

# SUDOER FILE:
```sudo visudo``` <br>
This command opens the SUDOER-EDITOR in which we can add all the specific access groups along with commands which they can perform

```sudo usermod -a -G (group) (username)```<br>
This commands ensure that the user is added to the specific access group in the SUDOERS-FILE

```sudo deluser (username) (group)```<br>
This command removes the user from a specific access group in the SUDOERS-FILE<br>
[Note: this command is specific to Ubuntu systems only]

# ORGANISATIONAL STRUCTURE
```root``` <br>
There can be only one root on the system itself and the password of the root will be strictly guarded against any brute-force attack<br>
[Note: use of su to switch user to root terminal must be limited]<br>

```admin```<br>
There can be many admin in the system, however only one single root can be allowed to create the admins in the system. They enjoy mild sudo privileges which are neccesary for their jobs.

```user```<br>
There can be many users in the system, who can be created by both the root and the admin and have the most limited functionality as the sudo privileges are concerned.
 
