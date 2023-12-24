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
 
# SUDOER-COMMAND-ALIASES:

Cmnd_Alias BASIC_CMDS = /bin/ls, /bin/cd, /bin/pwd, /bin/mkdir, /bin/rm, /bin/cp, /bin/mv, /usr/bin/touch
Cmnd_Alias NETWORK_CMDS = /sbin/ifconfig, /bin/ping, /usr/bin/ssh, /usr/bin/wget, /usr/bin/curl
Cmnd_Alias EDITOR_CMDS = /bin/nano, /bin/vi
Cmnd_Alias TOOLS_CMDS = /bin/grep, /usr/bin/awk, /usr/bin/sed, /usr/bin/find
Cmnd_Alias MISC_CMDS = /usr/bin/screen, /usr/bin/tmux, /usr/bin/zip, /usr/bin/unzip

Cmnd_Alias SYSTEM_CMDS = /usr/bin/sudo, /usr/bin/apt-get, /usr/bin/apt, /bin/systemctl, /usr/bin/top, /usr/bin/htop, /bin/df
Cmnd_Alias FIREWALL_CMDS = /usr/sbin/ufw, /sbin/iptables, /usr/sbin/firewalld
Cmnd_Alias ADMIN_CMDS = /usr/sbin/useradd, /usr/sbin/adduser, /usr/sbin/usermod, /usr/sbin/userdel, /bin/chown, /bin/chmod, /etc/sudoers, /etc/cron.d
Cmnd_Alias CONFIGURATION_CMDS = /usr/bin/git, /usr/bin/docker, /usr/bin/kubectl, /usr/bin/ansible, /usr/bin/terraform, /bin/systemctl
Cmnd_Alias ADDITIONAL_TOOLS_CMDS = /bin/netstat, /usr/sbin/tcpdump, /usr/sbin/iptraf, /usr/bin/nmap, /usr/bin/rsync, /usr/bin/scp
Cmnd_Alias HARDWARE_CMDS = /bin/mount, /sbin/mount.*, /bin/umount, /sbin/umount.*
