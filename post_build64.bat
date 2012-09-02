cls
cd \inetpub\wwwroot\IntrafoundationTCPClient\

copy tcpclientcom\Release64\*.dll .\

regsvr32 tcpclientcom.dll
