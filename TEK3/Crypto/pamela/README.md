# Pamela

## Description
Pamela is a PAM module coded in C. It provides an encrypted container mounted / created at your login on your UNIX machine for any users (encrypted using LUKS format).

The PAM module permission is **optional**

**Keep your data safe with this**

## Prerequisites
- Cryptsetup
- Root access for installation (as we install it in ```/lib/security/``` and change ```/etc/pam.d```)

## Usage
### Install
```make install```
Logout and re-login to see your new container mounted

### Uninstall
```make uninstall```
Logout to take effect

You can always test your configuration using ```make check```

## Credits
*Developed by Alexis Papadimitriou (PAM module) and me (Installation, cryptsetup)*