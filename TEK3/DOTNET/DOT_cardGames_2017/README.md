# Coinche.net
Coinche is an old card game based on the famous Belotte.

Here is a version coded in .NET based on a server/client architecture

**Your favorite game finally available**

## Stack
- .NET
- DotNetty
- Google Protobuf
- Doxygen Documentation*

## Documentation
This project is fully documented for your pleasure.

If you wish to re-generate the documentation, please run the following command in the root folder : ```doxygen coinche-documentation.dox```

Created documentation files are available under the ```Documentation``` folder (easy access through ```Documentation/html/index.html```. 

## Run
First, generate the project binaries in Visual Studio and then launch them with these commands :

Server (located in Server/bin/Release/.../) : ```dotnet Server.dll YOUR_IP YOUR_PORT```

Client (located in Client/bin/Release/.../) : ```dotnet Client.dll SERVER_IP SERVER_PORT```

----

## Made by WTF (Web Team Framework)
- Come Grellard
- Louis-Emile Uberti-Arès