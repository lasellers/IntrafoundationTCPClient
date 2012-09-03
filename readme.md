<html>
<head>
<title>Intrafoundation.TCPClient.3 COM v3.1</title>
</head>

<body index="index.html">

<table border=0 cellspacing=0 cellpadding=0 width="100%" class=header>
<tr>
	<td colspan=2 align=right width=80%>
	<div><strong><a href="http://www.intrafoundation.com/software/tcpclient.htm">I n t r a f o u n d a t i o n . T C P C l i e n t . 3</a></strong></div>
	</td>
	<td align=right width=20% rowspan=2><a href="index.html"></a></td>
</tr>
<tr>
	<td align=left>
<div class=headeroptional><!--C# .NET and -->C++ ATL COM Component</div>
<div class=headeroptional>FOR <a href="http://www.microsoft.com">ASP</a> and <a href="http://www.adobe.com">ColdFusion</a></div>
	</td>
	<td align=right>
<div></div>
<div><small>Open Source <!--64-bit .NET and -->64 and 32-bit C++ COM Object</small></div>
	</td>
</tr>
</table>

<table border=0 cellspacing=0 cellpadding=0 width=100%>
<tr valign=top>
	<td>

<table border=0 cellspacing=0 cellpadding=0 width=100%>
<tr valign=top>
	<td width=300 class=logo></td>
	<td align=right>
	by <strong>Lewis Sellers</strong> (aka TommyRaven)<br>
	I n t r a f o u n d a t i o n   S o f t w a r e<br>
	<br>
<tt><strong>v3.2, August 30th 2012</strong></tt><br>
<small>
<a href="http://www.intrafoundation.com">http://www.intrafoundation.com</a><br>
<a href="mailto:webmaster@intrafoundation.com">webmaster@intrafoundation.com</a><br>
</small>

<br>
<div style="color: #800000; font-family: Arial,serif; font-size: 80%;">
I'm available for short and long term contract work.<br>
Need extensions of some kind crafted or an extra pair of hands for straight up web programming? <a href="http://www.intrafoundation.com/contact-us/">Contact Me</a>.
</div>

	</td>
</tr>
</table>




<div style="background-color: #f0f020; font-size: 9pt; text-align: center; margin: 1px; padding: 3px;">
<strong>NOTICE:</strong> This software is now <b>64-bit</b>. If you need <b>32-bit</b> builds, they are located in the <tt>32bit_versions\</tt> folder.
</div>
<div style="background-color: #f0f060; font-size: 9pt; text-align: center; margin: 1px; padding: 3px;">
<b>NEW:</b> Follow the open source development of this software at <a href="https://github.com/lasellers">lasellers @ github.com</a>
or <a href="http://www.codeplex.com/site/users/view/lasellers">lasellers @ codeplex.com</a>.
</div>

<!-- DESCRIPTION -->
<p class=firstpara>
The <strong>TCPClient</strong> COM object allows you to talk to any Internet
server using TCP/IP such as: NNTP, POP3, SMTP, IRC, FTP, WHOIS, ECHO, RLOGIN,
FINGER, etc.
You could for instance ask an internic WHOIS server to return information on a domain name.
Or you could do a FINGER on JOHNC at IDSOFTWARE.COM to read John Carmack's .plan file.
Or query a POP3 email server, or an NNTP news server, or an FTP server, or just about anything else.
</p>
<p>
Simple, but useful.
</p>
<p>
More specifically it provides for asynchronous communications to any TCP/IP 
based server (which is just about everything higher-level on the Internet). 
You can send text messages to or receive messages from any of these servers. 
You can send or receive binary data back and forth from them as well. 
Additionally there is basic encoding/decoding function provided for the 
MIME Base-64 and UUENCODED formats you may encounter with news (NNTP) 
or mail (SMTP/POP3/IMAP4) servers.
</p>
<p>
This COM object provides only the elemental, base functionality you need to 
talk to these servers. As for what you're supposed to say to them and 
what do the messages they send back mean, well... Try reading the official 
RFC text documents to learn their languages.
</p>
<p>
But, as an example, a good way to start out with the SMTP mail server is to
simply hold out a hand and say:
</p>

<blockquote>
<tt>HELO</tt><br>
</blockquote>

<p>
What you do afterward is up to you....
</p>



<br>
<br>
<br>
<h3>REQUIREMENTS / SERVER PLATFORMS</h3>
<p>
This COM object was originally designed on and for Windows 2000 Professional and Windows XP Professional.
The 2012 version and up was rebuilt on Windows 7 64-bit.
It has not been tested under Windows 95, 98, ME or NT 3.51/4.
Nevertheless, it may work under some of them.
</p>
<p>
You should be able to use the COM from:
<ul>
<li>Adobe <a href="http://www.adobe.com">ColdFusion</a>
<li>Microsoft <A href="http://www.microsoft.com">ASP</a>
<li><a href="http://www.php4.net">PHP4</a>
<li>Any other engine or compiler that can use COM objects.
</ul>
</p>





<br>
<br>
<br>
<h3>INSTALLATION</h3>
<p>
The COM dwells in the file called <tt>tcpclientcom.dll</tt>.
To install, at the command prompt type: <tt>regsvr32 tcpclientcom.dll</tt>.
You may wish to copy it to your project or system folder first.
</p>
<p>
The precompiled file <tt>tcpclientcom.dll</tt> is root folder of the archive.
</p>
<p>
There are install.bat and uninstall.bat files included that you can simply click from Windows which will do the same.
</p>




<br>
<br>
<br>
<h3>UNINSTALLATION</h3>
<p>
At the command prompt type: <tt>regsvr32 /u tcpclientcom.dll</tt>.
</p>





<br>
<br>
<br>
<h3>THE EXAMPLE SCRIPTS</h3>
<p>
There are several example scripts included with this COM object.
Some are only partially done.
None are optimised for the protocols they use.
Addtionally, some are written by the author(s) of this software, whlie others have been developed by it's users.
</p>
<p>
For most of the examples you'll need to have the appropriate SERVER software installed on your local computer
(i.e., either ASP or ColdFusion).
</p>
<p>
For testing purposes most accounts are <strong>tcpclient</strong> with a password of <strong>tcpclient</strong>.
Domains, where used, are the the locally used <strong>foundation.local</strong> using the 192.168.0. Class C private subnet ip's for local testing.
This mimics the setup of the development server used here.
You do not need to set this up for the COM object -- only to use some of the localhost examples.
And you should be connected to the internet for some of them as they talk to other machines out there.
If you are not connected to the net and do not have a domain name server installed locally the tag may sit there for several seconds waiting for a name server to answer it before finally giving up.
</p>
<p>
You might want to look at the source of the scripts before you use them.
</p>
<p>
There are two subfolders.
One is called "send".
It's contents are sent out during some of the ftp and smtp/pop3 tests.
The "recv" folder is where these files are downloaded back to.
</p>

<br>
<p>
<em>Send in your own sample scripts.</em>
</p>


<br>
<br>
<br>
<h3>COPYRIGHT / TERMS OF USE</h3>
<p>
This software is Copyright (c) 2000, 2001, 2003, 2004, 2012 by Lewis A. Sellers.
It is not public domain, nor is it GPL'ed, but it is very close.
As long as you do not modify any files in the archive, nor add to them, nor delete any of them,
and do not charge for access to said archive you may redistribute the archive as you like.
</p>
<p>
You may use this software as-is with any software you wish, so long as said
archive is included unmodified with proper credits and link to it's homesite is included also
(<a href="http://www.intrafoundation.com/software/tcpclient.htm">http://www.intrafoundation.com/software/tcpclient.htm</a>).
</p>
<p>
You may modify and use the source code as you like -- with the understanding
that if you do, you still have to include the original, unaltered archive as
well as the aforementioned credits and link.
</p>
<p>
You may use this software in commerical applications, whether closed-source or open-source so long as the aforementioned unaltered archive is included with the application
and the aforementioned creditation and hyperlink are included.
</p>
<p>
If this software is used in a released project or included in a publication you are to make reasonable efforts to contact the author and notify them as to such.
The author of this software has a primary email address of: <a href="mailto:webmaster@intrafoundation.com">webmaster@intrafoundation.com</a>.
</p>
<p>
You use this software at your own risk.
</p>


<br>
<br>
<br>
<h3>THE HARNESS FILES</h3>
<p>
<strong>Q:</strong> What are all the "harness" folders about that are sometimes included with this software?
</p>
<p>
<strong>A:</strong> A "test harness" is just a simple command-line application that is used to quickly test portions of a program in an easy to debug environment.
Without using them, debugging a DLL that runs under a web server would take a very, very, very ... (did I mention very?) long time.
</p>
<p>
They are not needed to use this software. They are only included for completeness of the project and for use by others who wish to debug an issue.
</p>



<br>
<br>
<br>
<h3>PROTOCOL RFC'S</h3>
<p>
<strong>Q:</strong> Where can you get these RFC's I keep talking about?
</p>
<p>
<strong>A:</strong> They can be found at many sites across the interest.
Try:
</p>
<ul>
<li><a href="http://www.cis.ohio-state.edu/hypertext/information/rfc.html">http://www.cis.ohio-state.edu/hypertext/information/rfc.html</a>
<li><a href="http://www.rfc.net">http://www.rfc.net</a>
<li><a href="http://www.freesoft.org/CIE/RFC/index.htm">http://www.freesoft.org/CIE/RFC/index.htm</a>
</ul>
<br>
<br>
<br>


<h3>FIREWALLS</h3>
<p>
Firewalls.
It's almost impossible these days to safely be connected to your local area network, let alone the Internet,
without using a firewall (and a half dozen other anti-viral, anti-trojan, anti-spyware, etc programs).
We bring this up because, most likely, you're using this software via a web server such as Microsoft IIS or Apache.
This means this COM object will be talking to the network through THEM in some fashion.
You won't be getting a simple software message stating that say, Intrafoundation.TCPClient or Intrafoundation.UDPClient, etc
are wishing access to the network.
</p>
<p>
You will in fact most likely get this message:<br>
<tt>(10061) (Connection refused. No connection could be made because the target machine actively refused it. This usually results from trying to connect to a service that is inactive on the foreign host - i.e. one with no server application running.)</tt><br>
</p>
<p>
So no, you're going to have to specifically set up your firewall to allow network communication for this software.
With IIS in the default configuration ("Medium" Application Protection) this would theoretically mean enabling the infamous dllhost.dll, known as "COM Surrogate".
We say it's infamous because it's been used in a variety of ways by numerous viruses, worms, trojans and the like.
So much so that most software firewalls that have application protection will disable it by default.
</p>
<p>
If you set IIS Application Protection to "Low" it uses a process other than dllhost.dll, but low isn't generally a recommended setting.
When set to "High", against it uses a different process to run scripts through, namely Internet Information Services.
</p>
<p>
For a more detailed explaination of this topic, refer to your particular Web Server and Firewall manuals for exact information on this subject.
</p>
<br>
<br>
<br>


<h1>MANUAL</h1>
<a name="overview"><h3>TCP/IP OVERVIEW</h3></a>

<table border=1 class=function align=right width=50%>
<tr><th colspan=3>METHODS</th></tr>
<tr><th>name</th><th>input</th><th>output</th></tr>
<tr><td>Open</td><td>host (string), port (string)</td><td>connected (boolean)</td></tr>
<tr><td>Close</td><td></td></tr>
<tr><td>Send</td><td>text (string)</td></tr>
<tr><td>Recv</td><td></td><td>text (string)</td></tr>
<tr><td>SendRN</td><td>text (string)</td></tr>
<tr><td>RecvRN</td><td></td><td>text (string)</td></tr>
<tr><td>FlushRN</td><td></td><td></td></tr>
<tr><td>SendFile</td><td>filename (string)</td></tr>
<tr><td>RecvFile</td><td>filename (string)</td></tr>
<tr><td>RecvFileAppend</td><td>filename (string)</td></tr>
<tr><td>SendCSV</td><td>csv (string)</td></tr>
<tr><td>RecvCSV</td><td></td><td>csv (string)</td></tr>
<tr><td>SendFrame</td><td>frame-definition (string), frame</td></tr>
<tr><td>RecvFrame</td><td>frame-definition (string)</td><td>frame</td></tr>
<tr><td>FrameSize</td><td>frame-definition (string)</td><td>framesize (number)</td></tr>
<tr><td>EncodeFrame</td><td>frame-definition (string), field-name (string), field-value (string), frame</td><td>frame</td></tr>
<tr><td>DecodeFrame</td><td>frame-definition (string), frame, field-name (string)</td><td>field-value (string)</td></tr>
<tr><td>ClearLog</td><td></td></tr>
</table>

<p>
A few words first....
</p>
<p>
With TCP/IP there are two modes of communication that may be used:
Synchronous and Asynchronous.
Synchronous means that the client will send information, then the server will send back information, and then so on in that order.
Essentially a question and answer format.
</p>
<p>
For some services such as <strong>whois</strong> servers this works well. 
You send a <strong>whois</strong> server the domain name you want information on, and it returns the result to you.
It's a little like an SQL query that way.
</p>
<p>
<strong>finger</strong> and <strong>http</strong> also work fine with simple synchronous communications.
</p>
<p>
However, more complicated protocols such as <strong>ftp</strong> may be doing several things at once and in fact on different ports.
To simply get an <strong>ftp</strong> directory listing you would open communications to an <strong>ftp</strong> command port and request a directory listing.
The listing data then comes in on a <em>different</em> port.
If it's a large directory then the data being sent may take several seconds or minutes to transfer.
In the mean time your command port communications continues on.
</p>

<p>
This is what is meant by asynchronous communications.
</p>
<p>
This software uses asynchronous communication mode.
You can still talk to any server that operates in the simpler forms such as whois and finger.
It's just a little more work to determine when the server is done talking to you is all.
</p>
<p>
All TCP/IP communications comes in packets.
A packet can contain anywhere from 0 to 1536 bytes.
You can never tell beforehand how large any packet will be.
For example, you could recieve a response from a <strong>whois</strong> server in 10 packets of 1 byte each,
but generally you'll be sent data in as large of a packet as possible.
</p>
<p>
This object will automatically continue to receive packets and string it all together for you as long as the remote server continue to send them.
It will only stop if the remote server drops it's connection,
if it time's out
or if you setup a cutoff point.
</p>

<table align=right width=50%>
<tr><td>
	
<table border=1 class=function align=right width=100%>
<tr><th colspan=2>PROPERTIES (PUT)</th></tr>
<tr><td>timeout (alias set_timeout)</td><td>seconds</td></tr>
<tr><td>cutoff (alias set_cutoff)</td><td>bytes</td></tr>
<tr><td>blocksize (alias set_blocksize)</td><td>bytes</td></tr>
<tr><td>packetsize (alias set_packetsize)</td><td>bytes</td></tr>
<tr><td>keepalives (alias set_keepalives)</td><td>boolean</td></tr>
<tr><td>nagledelay (alias set_nagledelay)</td><td>boolean</td></tr>
</table>

</td></tr>
<tr><td>

<table border=1 class=function align=right width=100%>
<tr><th colspan=2>PROPERTIES (GET)</th></tr>
<tr><td>thread</td><td></td><td>number</td></tr>
<tr><td>version</td><td></td><td>string</td></tr>
<tr><td>copyright</td><td></td><td>string</td></tr>
<tr><td>description</td><td></td><td>string</td></tr>
<tr><td>instance</td><td></td><td>number</td></tr>
<tr><td>instances</td><td></td><td>number</td></tr>
<tr><td>Log</td><td>string</td></tr>
<tr><td>is_completed</td><td>boolean</td></tr>
<tr><td>is_connected</td><td>boolean</td></tr>
<tr><td>local</td><td>string "url"</td></tr>
<tr><td>remote</td><td>string "url"</td></tr>
<tr><td>bytessent</td><td>bytes (number)</td></tr>
<tr><td>bytesreceived</td><td>bytes (number)</td></tr>
<tr><td>byteslastsent</td><td>bytes (number)</td></tr>
<tr><td>byteslastreceived</td><td>bytes (number)</td></tr>
<tr><td>socket</td><td>socket (number)</td></tr>
<tr><td>is_cutoff</td><td>(boolean)</td></tr>
<tr><td>cutoff</td><td>bytes (long integer)</td></tr>
<tr><td>blocksize</td><td>bytes (long integer)</td></tr>
<tr><td>packetsize</td><td>bytes (long integer)</td></tr>
<tr><td>stack_recv_buffer</td><td>bytes (long integer)</td></tr>
<tr><td>stack_send_buffer</td><td>bytes (long integer)</td></tr>
<tr><td>recv_packets</td><td>(long)</td></tr>
<tr><td>send_packets</td><td>(long)</td></tr>
<tr><td>recv_faults</td><td>(long)</td></tr>
<tr><td>recvbuffer_faults</td><td>(long)</td></tr>
<tr><td>kbpssent</td><td>(floating point number)</td></tr>
<tr><td>kbpsreceived</td><td>(floating point number)</td></tr>
<tr><td>kbpslastsent</td><td>(floating point number)</td></tr>
<tr><td>kbpslastreceived</td><td>(floating point number)</td></tr>
<tr><td>ping</td><td>millieconds (integer)</td></tr>
<tr><td>timeout</td><td>seconds (floating-point)</td></tr>
<tr><td>last_timeout</td><td>milliseconds (integer)</td></tr>
<tr><td>mutex_sleep</td><td>(integer)</td></tr>
<tr><td>mutex_locks</td><td>(integer)</td></tr>
<tr><td>mutex_sleep</td><td>(integer)</td></tr>
<tr><td>is_keepalives</td><td>(boolean)</td></tr>
<tr><td>is_nagledelay</td><td>(boolean)</td></tr>
</table>

</td>
</tr>
</table>

<p>
So, when retrieving data from a remove server via tcp/ip you'll continue to recv(ieve) data until you're done.
How do you know when you're done?
Some protocols like <strong>ftp</strong> explicitly tell you how many bytes to expect.
With others like <strong>whois</strong> you just continue recieving until they're done and close the connection on you (rude as it may sound).
For others you may just have to read their RFC docs and guess.
</p>

<a name="peak_performance"><h4>PEAK PERFORMANCE: TIMEOUTS & CACHE MISSES</h4></a>
<p>
One thing that can not be stressed enough about this COM object is that is
understands nothing about the higher-level application protocols such as POP3,
NNTP, SMTP, NTP, etc.
The functions are generic.
That is, they have not been optimized to take the cues most protocols send to tell you when they are finished sending a block of data.
Recv, for example, will continue to receive and accumulate data forever until 1) the remote server closes the session (normally or abnormally) 2) you use the optional maximum byte transfer limit <em>cutoff</em> property or 3) the <em>timeout</em> limit is exceeded.
(This is true for all the send/receive functions with the execption of RecvRN, which is a special case.)
</p>

<p>
What this means is that, if you are on good T3 connection, that issuing one single Recv command could cause the COM object to download a block of data for hours, hundreds and hundreds of gigabytes of data.
Eventually your storage devices would be flooded and your machine crash -- unless you use either the above mentioned <em>cutoff</em> or <em>timeout</em> properties to impose limitations.
</p>
<p>
The concept of a maximum byte cutoff is fairly obvious (see the function docs for more details).
As for the timeout, for this COM it specifies the maximum amount of time the COM will wait around for the remote server to send some data, any data, before it gives up trying.
On LAN's you might be able to get away with timeouts as low as 10 or 20 milliseconds.
On the internet 5 seconds or more is generally required.
</p>
<p>
Anyway, besides preventing your machine from crashing there are performance issues to consider.
Some protocols such as WHOIS and HTTP are simple things; you issue them a command to retrieve data and they do so and close the connection.
Recv and the others work fine here.
They grab all the data the remote server sends them until it tells the COM object it's done and closing the session.
</p>
<p>
Things get tricker with say POP3.
POP3 (Post Office Protocol 3) is the protocol you use to receive mail from your internet mail box.
It is command-driven.
That is, you open a connection, send a command, get a response.
While the connection is open you'll probably send several commands and read several responses.
If you've subscribed to a mailing list that generates a hundred or so emails a day you could be issuing several hundred commands to the POP3 server to transfer all your email and delete it afterward before closing a connection.
</p>
<p>
You could use Recv, etc to read the responses, but, Recv remember knows nothing of POP3 protocols.
It will continue to try to read data until a timeout occurs.
If you have the timeout set to say 5 seconds that means it would take something like 100 (emails) times 5 (seconds) or 500 seconds to transfer these emails.
</p>
<p>
That's not good.
</p>
<p>
For any protocol that is command-driven you should use RecvRN.
It specifically caches all data it recieves and only retrives more from the server when it's buffer is empty.
By using RecvRN you can avoid any needless timeout issues.
</p>


<a name="spec_limitations"><h4>SPEC LIMITATIONS</h4></a>
<p>
How big a block of data can this transfer?
Well, how much memory do you have?
Earlier versions sometimes crashed under IIS5/ASP because it was running into it's 256kb stack limit,
but current versions are, to our knowledge, unlimited.
Or that is, limited only by your RAM and drive space.
</p>
<p>
Is thread-safe? Yes. It should be.
The core tcp class has been hammered from time to time by multiple computers.
Far as is know, there are no memory leaks and it threads fine.
</p>
<p>
Accidents could happen between versions however.
If you notice any memory or threading issues, just yell.
</p>


<h4>SSL</h4>
<p>
There are plans for SSL (Secure Sockets Layer) to be added in the future.
Currently however any SSL specific functions in this COM object will silently fail.
</p>






<br>
<br>
<br>
<a name="frame"><h3>FRAMES</h3></a>
<p>
New for 3.x is the concept of "frames".
</p>
<p>
There are some protocols running on top of TCP/IP that exchange data as a set of binary fields of fixed size.
Before 3.x these were somewhat difficult to handle as the COM function were primarily aimed at handling text strings, leaving the task of manipulating any binary data received up to the ingenuity of the person writing the scripts using it (i.e., _you_.)
</p>
<p>
The addition of five new functions named: SendFrame, RecvFrame, FrameSize, EncodeFrame and DecodeFrame change this.
All of these functions make use of what is called a "frame-definition".
The frame definition of the UDP :) protocol NTP (Network Time Protocol) looks like this:
<tt class=quote>
"+2 LI,+3 VN,+3 Mode,+8 Stratum,+8 Poll,+8 Precision,+32 RootDelay,+32 RootDispersion,+64 ReferenceIdentifier,+64 ReferenceTimeStamp,+32 OriginateTimestamp,+64 ReceiveTimestamp,+64 TransmitTimestamp,s12 Authentication"
</tt><br>
</p>
<small>(And before you ask why don't I use a TCP protocol for an example, the answer is just wrote a SNTP time client two days before the rlease of 3.0 so it's fresh in my mind.)</small><br>
<p>
Frame definition consists of a comma seperated set of three field items. These are:
<ol>
<li>Endian indicator</li>
<li>Bit length</li>
<li>Field-name</li>
</ol>
</p>
<p>
The endian indicator is either "+" for Big Endian (used by most network protocols and Apple computers) and "-" for Little Endian, use for most everything else in the world include Intel/AMD processors.
</p>
<p>
Immediately following the endian flag (no spaces) is the number of bits the data of this field is allowed to occupy. 8 BITS of course is a BYTE. 16 BITS is a WORD, and so on.
A "+32", to recap, would mean a 32-bit DWORD in big-endian/network format.
</p>
<p>
Lastly, seperated by  a space, is the name of the field. The field-name is used to allow easy referencing by the EncodeFrame and DecodeFrame functions.
</p>

<h5>Bit Lengths</h5>
<p>
Bit lengths can be up 64 bits. HOWEVER: Internally this software operates on all frame fields as binary stream with a 64-bit window. The short of this is that as long as the field is on a byte boundry, it can be up to 64 bits in size. If it is not on a boundry then there may be as little as 56 bits of resolution available due to loss of precise by shift/mask operation.
</p>
<p>
This technical limitation is however, not generally something to be concerned over as most protocols that use 64-bit data usually have them aligned on _32-bit_ boundries as this is more efficient on modern processors on network devices.
Only if your data is not byte-aligned will it be limited to at most 56 bits of resolution.
</p>

<h5>On EncodeFrame and Frame reuse</h5>
<p>
After glancing at the Frame functions it should be noted that the "Frame" itself is binary data contained within a BSTR.
This is to be considered only a temporary way to aggregate and hold your data.
The raw "frame" data itself is generally non-printable and can only be created or acessed with the EncodeFrame and DecodeFrame functions.
</p>
<p>
It should especially be noted that EncodeFrame will encode a new field upon _any_ BSTR you pass it, producing a legal "Frame" out of this data.
</p>





<br>
<br>
<br>
<h2>METHODS</h2>

<h4>Open address, port</h4>
<table class=function>
<tr><th>Parameters</th><td>address (string), port (string)</td></tr>
<tr><th>Returns</th><td>boolean</td></tr>
</table>
<p>
Opens a TCP/IP connection to the server on the specified host and port.
If this fails the method returns a "false".
If it succeds it returns a "true".
</p>
<p>
The address can be a dotted ip address or a registered domain name or subdomain.
The port is typically a port number, but it will also accept some well known port names such as "whois".
</p>
<p>
Opening a connection resets the running error log.
</p>



<h4>Close</h4>
<table class=function>
<tr><th>Parameters</th><td></td></tr>
<tr><th>Returns</th><td></td></tr>
</table>
<p>
Closes the current socket connection.
If the socket is already closed (by the remote server for example) you should
still perform a close on your local machine as well.
If, you attempt to open a socket, but it does not connect, then you do not have
to close it (but you can still issue a Close if you want to.)
</p>
<p>
Note that once a socket is closed the values of many properties, such as 
<em>bytesreceived</em>, become unavailable.
</p>


<h4>Send text</h4>
<table class=function>
<tr><th>Parameters</th><td>text (string)</td></tr>
<tr><th>Returns</th><td>"length", a long integer</td></tr>
</table>
<p>
Sends a block string of text to the remote server.
</p>


<h4>SendRN text</h4>
<table class=function>
<tr><th>Parameters</th><td>text (string)</td></tr>
<tr><th>Returns</th><td>"length", a long integer</td></tr>
</table>
<p>
Sends a string of text and an appended "\r\n" sequence, otherwise known as CRLF, CHR(13) & CHR(10) or a CARRIAGE RETURN and a LINEFEED.
Most TCP/IP protocols require an RN sequence to be sent before executing any commands you send them.
</p>
<p>
The RN or CRLF sequence is, fyi, the character codes sent from your keyboard when you press the RETURN (or ENTER) key.
Make sense now?
</p>


<h4>FlushRN</h4>
<table class=function>
<tr><th>Parameters</th><td></td></tr>
<tr><th>Returns</th><td></td></tr>
</table>
<p>
If you use RecvRN then this software will automatically create an input buffer where all the data it's received is stored until subsequent RecvRN's exhaust the buffer.
For instance, if you connect to a HTTP server and send the commands to grab a web page, then the next time you do a Recv or a RecvRN the HTTP server will mostly likely send the results back in one large packet.
If you call Recv you'll get back all of this data at once.
If you call RecvRN it will return to you only one line at a time, however, the data itself will still remain in mmeory on your computer until you've called RecvRN enough times to read it all.
(Actually, technically, each time you call RecvRN it removes the line it returns from memory.)
</p>
<p>
In any event, you may have reason to want to force this buffer to be cleared.
For instance, you've read the important header information you needed and don't want to bother prasing the rest of it before you issue another command.
This function completely clears that internal buffer.
</p>


<h4>Recv</h4>
<table class=function>
<tr><th>Parameters</th><td></td></tr>
<tr><th>Returns</th><td>"text", a string</td></tr>
</table>
<p>
Gets data from the remote server as a string of text.
Recv will continue to accumulate data from the remote server until it closes
connection or the link times out (see the timeout property).
</p>
<p>
If the remote server doesn't not close connection during a Recv (as HTTP will do)
then you will suffer a timeout.
</p>


<h4>RecvRN</h4>
<table class=function>
<tr><th>Parameters</th><td></td></tr>
<tr><th>Returns</th><td>"line", a string</td></tr>
</table>
<p>
The RecvRN function retrieves one CRLF (aka RN) terminated line at a time from a
remote server.
The trailing CR (carriage return) and LF (line feed) control codes are stripped.
</p>
<p>
Unlike Recv, RecvRN uses a cache buffer. It only asks the remote server for more
data if it can not find a CRLF terminated string in it's cache.
Is this important? Oh yes.
With Recv you blindly ask server to return data until it closes connection or it
errors with a timeout.
This is fine for HTTP connections,
but for talking with command driven POP3, SMTP, etc where the tcp connection
remains open you will encounter a timeout for every Recv issued.
Timeouts can be costly in performance.
</p>
<p>
If there is no remaining data in the buffer and the remote server does not have
additional data waiting RecvRN will return a blank string and timeout.
You can check TIMEDOUT to see if the last RECVRN failed.
</p>


<h4>SendFile filename</h4>
<table class=function>
<tr><th>Parameters</th><td>filename (a string)</td></tr>
<tr><th>Returns</th><td></td></tr>
</table>
<p>
Sends the entire contents of a file as binary data.
</p>


<h4>RecvFile filename</h4>
<table class=function>
<tr><th>Parameters</th><td>filename (a string)</td></tr>
<tr><th>Returns</th><td></td></tr>
</table>
<p>
Receives all the binary data from the remote server until it closes the socket or timeouts.
This data is appended to the specifed file.
If the file does not exist it is created.
</p>

<h4>RecvFileAppend filename)</h4>
<table class=function>
<tr><th>Parameters</th><td>filename (a string)</td></tr>
<tr><th>Returns</th><td></td></tr>
</table>
<p>
The same as RecvFile, except that data recveived is appended to the end of the file specified.
</p>


<h4>SendCSV comma-seperated-values</h4>
<table class=function>
<tr><th>Parameters</th><td>comma-seperated-values (a string)</td></tr>
<tr><th>Returns</th><td></td></tr>
</table>
<p>
For the more advanced among you, this can be very useful.
A byte of course is a binary value of 0 to 255 inclusive, and bytes are the foundation of all TCP/IP communications.
By specifying a string decimal numbers seperated by commas (for example "1,255,123,131,13,10,0"),
this function will convert them to bytes codes before sending them on.
</p>
<p>
Primarily this is of use with TELNET-type servers which use embedded byte-codes that have no keyboard equivilent.
You can also use it to build binary file formats, but that's a more complicated example.
</p>


<h4>RecvCSV</h4>
<table class=function>
<tr><th>Parameters</th><td></td></tr>
<tr><th>Returns</th><td>comma-seperated-values (a string)</td></tr>
</table>
<p>
Instead of receiving a purely text string, any data recved is decoding in a a string of comma seperated numbers.
The numbers represent bytes as values of 0 to 255 inclusive.
</p>

<h4>ClearLog</h4>
<table class=function>
<tr><th>Parameters</th><td></td></tr>
<tr><th>Returns</th><td></td></tr>
</table>
<p>
Clears the error log.
(Function formerly called "Clear" in 2.x.)
</p>


<h4>SENDFRAME frame-definition, frame</h4>
<table class=function>
<tr><th>Parameters</th><td>frame-definition (a string), frame</td></tr>
<tr><th>Returns</th><td></td></tr>
</table>
<p>
Sends the binary data in "frame" after computing the frame-size from the "frame-definition".
The function itself operates the same as the Send function with a slight amount of overhead to handle the frame data.
</p>
<p>
See the <a href="#frame">frame</a>  section for more details.
</p>

<h4>RECVFRAME frame-definition (returns frame, a binary string)</h4>
<table class=function>
<tr><th>Parameters</th><td>frame-definition</td></tr>
<tr><th>Returns</th><td>"frame", a binary string</td></tr>
</table>
<p>
Receives data from the stream the same as the Recv function, except that it always tries to return an amount of data equal to the framesize as specified in the frame-definition.
Any additional data that was received at that time will remain in the internal recv buffer and can be retreive by subsequent calls to any of the "Recv" functions including Recv, RecvRN, RecvCSV and/or RecvFrame.
</p>
<p>
If it does not recieve any data before timeout occurs it will return a NULL string.
</p>
<p>
See the <a href="#frame">frame</a>  section for more details.
</p>

<h4>FRAMESIZE frame-definition (returns "framesize", a number)</h4>
<table class=function>
<tr><th>Parameters</th><td>frame-definition (a string)</td></tr>
<tr><th>Returns</th><td>"framesize", a long integer</td></tr>
</table>
<p>
Given a valid frame-definition this function will return the number of bits that will be required to encode it.
For example "+8 Mode, +4 Align, +4 Status" would return 16 if given to the FrameSize function.
</p>
<p>
Primarily, this function can be used to valid your math skills when computing the framesize by hand.
</p>
<p>
See the <a href="#frame">frame</a>  section for more details.
</p>


<h4>ENCODEFRAME frame-definition, field-name, field-value, frame</h4>
<table class=function>
<tr><th>Parameters</th><td>frame-definition (a string), field-name (a string), field-value (a string), frame</td></tr>
<tr><th>Returns</th><td>"frame", a binary string</td></tr>
</table>
<p>
EncodeFrame creates the binary data structure that composes a frame that you wish to send.
It does this by issuing in succession a serious of EncodeFrame commands with the field-name you wish to add/change and it's value.
</p>
<p>
For example:
<tt class=quote>
enc=obj.EncodeFrame("s20 Name,s20 Genre","Name","Blue Danube","")
</tt><br>
creates a binary string of a size equal to 40 bytes and populates the first 20 bytes with the ASCII string "Blue Danube".
The last 20 bytes where "Genre" would go would be blank until or unless you populate it as well.
</p>
<p>
For example:
<tt class=quote>
enc=obj.EncodeFrame("s20 Name,s20 Genre","Genre","Classical",enc)
</tt><br>
Takes the variable "enc" which is holding our frame data and adds the string "Classical" to the last 20 bytes.
</p>
<p>
This function take an existing frame as an input, returning a new frame that has the specified field data changed within it.
Generally, you would just pass to it the same string as you return from it.
</p>
<p>
Note that this function will take _any_ string as an input and will modify only the area as specified by the field-name for the frame-definition.
If the input frame contains more data than the frame-definition allows, the data will be truncated.
If less, then it will be zero-padded.
In other words, it operates upon a "dirty" data principle -- You can RecvFrame a frame, change one field, and send it directly back without having to reencode the entire thing.
</p>
<p>
See the <a href="#frame">frame</a>  section for more details.
</p>


<h4>DECODEFRAME frame-definition, field-name, frame</h4>
<table class=function>
<tr><th>Parameters</th><td>frame-definition (a string), field-name (a string), frame</td></tr>
<tr><th>Returns</th><td>"field-value", a string</td></tr>
</table>
<p>
Uses the frame-definition to extract from the binary frame data the value for the field specified by field-name. 
For example, the following extracts the "Mode" data from an NTP (Network Time Protocol) formatted frame:
</p>
<p>
<tt class=quote>
Mode=obj.DecodeFrame("+2 LI,+3 VN,+3 Mode,+8 Stratum,+8 Poll,+8 Precision,+32 RootDelay,+32 RootDispersion,+64 ReferenceIdentifier,+64 ReferenceTimeStamp,+32 OriginateTimestamp,+64 ReceiveTimestamp,+64 TransmitTimestamp,s12 Authentication","Mode",my_frame_i_just_received)
</tt><br>
</p>




<br>
<br>
<br>
<h2>PROPERTIES</h2>

<p>
All properties are optional.
They can be extremely useful for optimizing the performance of your code however,
particular where high-performance, highly-responsive operation is required.
</p>

<h3>PUT</h3>

<h4>timeout/set_timeout seconds</h4>
<table class=function>
<tr><th>Parameter</th><td>seconds (a floating-point number)</td></tr>
</table>
<small>(Note: Has an alternative alias with a "set_" prefix for older versions of ColdFusion which do not properly handle get/put COM names.)</small><br>
<p>
The timeout setting is very important to understand for peak performance.
The defines how long any of the Send, Recv, SendRN, RecvRN, etc function will wait for a response from the remote server before giving up.
This is a float point number representing the number of seconds.
Millisecond precision can be set using the fractional portion.
For example the default setting is 100milliseconds.
In ASP you would set this as: <tt>obj.timeout=0.100</tt>.
</p>
<p>
It is very important to note that because of internet congestion or other situations such as heavy server load
that you may not be able to receive the entire text of a transmission at a single time with the default setting of 100ms.
Adjust it up to whatever you feel is appropriate.
</p>
<p>
For simple protocols such as <strong>whois</strong> and <strong>http</strong> timeout's of 15 seconds or higher are fine in most cases.
More complex protcols such as ftp are a <em>completely</em> different matter however.
</p>
<p>
ftp, and a few other protocols such as irc maintain a continuous open tcp session.
When they complete a command (such as listing the files in the current directory, or changing to a different directory) they <strong>do not</strong> close the session.
They perform the command and wait for you to issue another one.
Setting the timeout to 15 seconds in this case would be agonizing; everytime you changed to different folder on the remote server it would wait 15 seconds (unless the server remotely terminates you).
</p>
<p>
Caution: Unless the socket times out or the remote server remotely terminates the session, 
the RECV* functions will continue to retrieve data without any limits.
</p>
<p>
It should be noted the timeout property has no effect unless a socket is currently open.
Other than that, you may change the timeout at any time, customizing the com object's patience to fit the expected latency of any commands issued.
</p>
<p>
The thing about all this is -- unless you're using RecvRN -- you're ALWAYS going to be timing out unless the sessions terminates normally (or abnormally even).
This is because it's blindly waiting to recieve all the data it can.
</p>


<h4>cutoff/set_cutoff bytes</h4>
<table class=function>
<tr><th>Parameter</th><td>bytes (a long integer)</td></tr>
</table>
<small>(Note: Has an alternative alias with a "set_" prefix for older versions of ColdFusion which do not properly handle get/put COM names.)</small><br>
<p>
Normally you'll never have to use this, BUT... it is here if you do.
This puts a hard limit on the amount of data for any transfer.
If you try to connect to a continuously streaming site
(something pumping out a live multimedia stream for example)
you'll obviously need to tell the RECV* functions to please-in-the-name-of-god stop! :) overwise it will continue to download data for ever...
eventually overflowing your hard drives and crashing your system.
</p>
<p>
For example, if you set a cutoff of 65536 (aka 64kb) then a RECVFILE will stop after it downloads 64kb.
You can then issue it again in a conditional loop to continue processing.
</p>
<p>
Cutoff uses an integer number that is in bytes.
Setting a cutoff of 0 disables the limit.
Any other value engages it.
By default it is always disabled.
</p>
<p>
An important technical note:
TCP/IP sends data in packets that can range anywhere from 0 to 65526 bytes in size.
Keeping this in mind, when you, for example, specify a cutoff of 6000 bytes you are NOT going to receive back a block of data exactly equal to 6000 bytes in length.
The cutoff is only checked after each packet of data is accumluated so you could have up to ~65526 bytes more than your limit.
ie, up to 7536 bytes.
</p>
<p>
To give a precise cutoff would require an integrated buffering system that was deemed too deterimental at this time.
(But if I start having to work with streaming video, you can bet I'll take the time to add precision block control and bit-level structure handling.)
</p>
<p>
Cutoff should be considering a rough "panic limit", not a precision tool.
</p>


<h4>blocksize/set_blocksize bytes</h4>
<table class=function>
<tr><th>Parameter</th><td>bytes (a long integer)</td></tr>
</table>
<small>(Note: Has an alternative alias with a "set_" prefix for older versions of ColdFusion which do not properly handle get/put COM names.)</small><br>
<p>
Affects Recv, RecvRN, RecvCSV and RecvFile.
By default is 65536 bytes.
</p>
<p>
A major inhibitor of performance when moving very large streams of data around
(30mb files for example) is the overhead associated with managing the memory to
hold this data. Specifically, the overhead in creating and destroying
continuous memory blocks whenever a block of data "grows".
</p>
<p>
In our case, as data is streamed from the remote server to this COM object it is
tacked on to an internal buffer. Using the default tcp buffer size of 8192 bytes
you'd have to "grow" this memory buffer some 3840 times in the course of a transfer of a 30MB file.
This overhead is very resource expensive, so we make use of the <em>blocksize</em>
property to allow you to specify how big of a block of free memory we should allocate
everytime we "grow".
</p>
<p>
All this means is that when you receive the first 8192 bytes of the aforementioned 30mb file,
if you had a blocksize of 1mb (1048576) then we'd pre-allocate memory in blocks of 1mb.
This reduces the number of times we'd have to grow the buffer down to only 29.
</p>
<p>
Of course, it also means we're allocating a lot of memory as we go along.
You simply have to figure out what the right balance of RAM and processing power is best
for what you're doing.
</p>
<p>
In general this shouldn't be an issue you'd have to really worry about unless
you're moving files around that are say half a MB or or more in size.
For the most part only ftp client writers will need to worry about this.
Although if large mail attachments are involved then SMTP, POP3 and NNTP client
code might need to make use of it as well for performance.
</p>
<p>
The minimum blocksize is that of the tcp buffersize (currently at 8192 bytes).
</p>


<h4>packetsize/set_packetsize bytes</h4>
<table class=function>
<tr><th>Parameter</th><td>bytes (a long integer)</td></tr>
</table>
<small>(Note: Has an alternative alias with a "set_" prefix for older versions of ColdFusion which do not properly handle get/put COM names.)</small><br>
<p>
Sets the assumed packet size for outgoing data.
</p>
<p>
When sending data it is send in "packets" or blocks of a set maximum size.
As a general rule of thumb the size of these packets are anywhere from 512 to 1536 bytes.
</p>
<p>
This software uses the default of 65536 bytes unless you override it.
The standard default for TCP/IP stacks however is 512 bytes.
The choice of 65536 bytes comes about by performance tests over an Ethernet LAN network when this software was initially designed.
65536 bytes was the "sweet spot" that gave the highest throughput performance.
Of course, depending onthe hardware you're using, you may wish to change the assumed packet size.
</p>

<h4>keepalives/set_keepalives flag</h4>
<table class=function>
<tr><th>Parameter</th><td>flag (a boolean)</td></tr>
</table>
<small>(Note: Has an alternative alias with a "set_" prefix for older versions of ColdFusion which do not properly handle get/put COM names.)</small><br>
<p>
Sets "keepalives" to on or off. As to whether this functions depends upon the TCP/IP stack provider, but if so, helps to keep a connection open during extended peroids of inactivity.
</p>

<h4>nagledelay/set_nagledelays flag</h4>
<table class=function>
<tr><th>Parameter</th><td>flag (a boolean)</td></tr>
</table>
<small>(Note: Has an alternative alias with a "set_" prefix for older versions of ColdFusion which do not properly handle get/put COM names.)</small><br>
<p>
Turns on or off the Nagle algorithm.
</p>





<h3>GET</h3>

<p>
NOTE:
Due to the way this COM is implimented as a shell over a set of "safe" general purpose C++ classes,
most properties are not available if you are not connected to a server.
</p>

<h4>is_completed</h4>
<table class=function>
<tr><th>Returns</th><td>a boolean</td></tr>
</table>
<p>
Boolean return of "false" or "true".
Indicates whether the TCP session has completed normally.
That is to say, that the remote server has sent the customary 0 byte packet signalling the end-of-file then closed the connection.
</p>
<p>
For example, if a connection is accidently lost (lightning strikes the power lines, someone unplugs your modem, etc) then connection will be set to "0" and completed will be "0".
You will never get a "1" for completed in this case.
</p>


<h4>is_connected</h4>
<table class=function>
<tr><th>Returns</th><td>a boolean</td></tr>
</table>
<p>
Boolean return of "false" or "true".
Indicates whether the connection is still currently active.
</p>

<h4>is_keepalive</h4>
<table class=function>
<tr><th>Returns</th><td>a boolean</td></tr>
</table>
<p>
Boolean return of "false" or "true".
Indicates whether the "keepalives" are on or off.
</p>

<h4>is_nagledelay</h4>
<table class=function>
<tr><th>Returns</th><td>a boolean</td></tr>
</table>
<p>
Boolean return of "false" or "true".
Indicates whether the Nagle delay algorithm is on or off.
</p>



<h4>local</h4>
<table class=function>
<tr><th>Returns</th><td>a string</td></tr>
</table>
<p>
Returns a string with the <em>address:port</em> url of the local end of the connection.
</p>


<h4>remote</h4>
<table class=function>
<tr><th>Returns</th><td>a string</td></tr>
</table>
<p>
Returns a string with the <em>address:port</em> url of the remote end of the connection.
</p>


<h4>bytessent</h4>
<table class=function>
<tr><th>Returns</th><td>bytes, a long integer</td></tr>
</table>
<p>
The total number of bytes sent to the remote server.
</p>


<h4>bytesreceived</h4>
<table class=function>
<tr><th>Returns</th><td>bytes, a long integer</td></tr>
</table>
<p>
The total number of bytes received from the remote server.
<p>
</p>


<h4>socket</h4>
<table class=function>
<tr><th>Returns</th><td>an integer</td></tr>
</table>
<p>
The current socket (session) number being used.
</p>


<h4>Log</h4>
<table class=function>
<tr><th>Returns</th><td>a string</td></tr>
</table>
<p>
Gets list of all error messages accumulated since the object was created.
Clear out the error cache with the ClearErrorLog method.
Note that issuing an "Open" command automatically clears the error log as well.
</p>


<h4>byteslastreceived</h4>
<table class=function>
<tr><th>Returns</th><td>bytes, a long integer</td></tr>
</table>
<p>
Number of bytes of data received from last RECV* method.
</p>


<h4>byteslastsent</h4>
<table class=function>
<tr><th>Returns</th><td>bytes, a long integer</td></tr>
</table>
<p>
Number of bytes of data sent with last SEND* method.
</p>


<a name="timeout"><h4>timeout</h4></a>
<table class=function>
<tr><th>Returns</th><td>"seconds", a floating-point number</td></tr>
</table>
<p>
Returns the current timeout settings in milliseconds.
This property is set by the <em>timeout</em> put property.
By default it is usually 200 milliseconds.
</p>
<p>
See the general <a href="#overview">overview</a> on TCP/IP for a discussion on how this affects operations.
</p>


<a name="last_timeout"><h4>last_timeout</h4></a>
<table class=function>
<tr><th>Returns</th><td>"seconds", a floating-point number</td></tr>
</table>
<p>
If a RECV* method times outs, this will tell you.
If it is 0 then the last RECV* used did not time out.
Otherwise it is the seconds the method waited before giving up.
</p>
<p>
TIMEDOUT is used to dynamically adjust for network latency conditions.
How you do this of course is completely up to you.
</p>

<h4>is_cutoff (returns a boolean)</h4>
<p>
If "true" then the previous Recv stopped becaused it reached the prearranged cutoff limit.
Otherwise "false".
</p>

<h4>cutoff (returns "bytes", a long integer)</h4>
<p>
Returns the cutoff, if set, in bytes.
If unset this will be "0".
</p>

<h4>blocksize (returns "bytes", a long integer)</h4>
<p>
The current operating blocksize.
</p>

<h4>recv_packets (returns a long integer)</h4>
<p>
The number of times data has been requested from the remote server.
</p>

<h4>send_packets (returns a long integer)</h4>
<p>
The number of times data has been sent to the remote server.
</p>

<h4>recv_faults (returns a long integer)</h4>
<p>
The number of times when doing a recv* that a packet had to be requested from the network.
</p>

<h4>recvbuffer_faults (returns a long integer)</h4>
<p>
The number of times while doing a RecvCRLF or RecvFrame that more data had to be requested from the network.
</p>

<h4>stack_recv_buffer (returns a long integer)</h4>
<p>
The size of the TCP/IP stack's recv buffer.
</p>

<h4>stack_recv_buffer (returns a long integer)</h4>
<p>
The size of the TCP/IP stack's send buffer.
</p>

<h4>kbpssent (floating point number)</h4>
<p>
The computed kilobytes per second of data sent.
</p>

<h4>kbpsreceived (floating point number)</h4>
<p>
The computed kilobytes per second of data received.
</p>

<h4>kbpslastsent (floating point number)</h4>
<p>
The computed kilobytes per second of the last block of data sent.
</p>

<h4>kbpslastreceived (floating point number)</h4>
<p>
The computed kilobytes per second of the last block of data received.
</p>

<h4>ping (integer, milliseconds)</h4>
<p>
Ping is computed automatically for you.
Internally it is computed by simply starting a timer whenever a udp packet is sent and stopping it the next time you recieve a packet.
Because of this please be aware that if you send a udp then do a lot of computations inbetween that and when you attempt to recieve the packet that the ping numbers may be off.
</p>
<p>
This is in milliseconds.
</p>

<h4>instance (integer)</h4>
<p>
If you code calls several instances of this COM into existance at once you can determine which instance you are talking to by calling this.
</p>
<p>
This is an integer number, where the default first instance is always numbered "1".
</p>

<h4>instances (integer)</h4>
<p>
See "instance".
Calling this returns the number of instances of this COM object that have been called into existance since your server has been rebooted.
</p>
<p>
Note: When using this COM in desktop software the instance number will reset itself when the software is closed and restarted.
When used in sever-side software, as long as the COM stays loaded in memory, then every time the COM is called the instances number will increase by one.
</p>
<p>
Instances/Instance are mainly of use with debugging/optimizing the COM instantation process.
</p>
<p>
This is an integer number, where the default first instance is always numbered "1".
</p>

<h4>mutex_locks (integer)</h4>
<p>
In a multithreaded environment where you are using the same instance of this software there can be operation collisions resulting in garbled or intermixed data.
Tcpclient as of 3.00 supports a thread-safe operation which blocks or stalls operations where a collision might occur.
This number is the count of blocking waits that have been encountered.
In normal use, this would always be zero.
When used on multi-processor systems with the COM as an Application scope object under high stress the number may climb quite high.
</p>


<h4>mutex_sleep (integer)</h4>
<p>
See mutex_locks.
Returns the total amount of milliseconds the COM object has sleep waiting for a mutex to unlock.
</p>





<br>
<br>
<br>
<a name="versionhistory"><h1>VERSION HISTORY</h1></a>

<ul>

<li><b>3.2</b> August 30th 2012.
<p>
Compile for 64-bit support in addition to 32-bit.
</p>
<p>
For unknown reasons the separate <tt>classes\</tt> folder with common code between this a  few other projects was not bundled in the last uploaded version of this app. Thus, I have had to pull it from other sources. The various files were slightly out of temporal sync, thus I've had to rebuild the project more from scratch than anticipated.</p><p>
The 3.2 version pulls some of its sources from a partial port to Macintosh OS X I did years ago but never released.</p><p>
From now on, each project keeps it's own separate copy of any shared files.
Especially important given that it is going to be released on github and codeplex.
</p>
<p><b>This version should be considered possibly unstable as it has not been extensively retested.</b></p>
<p><b>TO DO:</b>
Make C# COM interop .NET DLL or perhaps pinvoke a c wrapped version.
Not interested in using C++/CLI.
</p>
</li>


<li><b>3.1</b> - November 5th 2004.
<p>
Updated the C++ classes it shares with several other projects, so recompiled.
Cleaned up for the relaunch of the <a href="http://www.intrafoundation.com">Intrafoundation</a> web site.
</p>
</li>

<li>
<b>3.0</b> - April 26th 2004.
<p>
After letting the project sit there a while, came back to it and decided to completely remove all the new message encoder/decoding classes and give them their own seperate COM object.
This COM should be lean and mean -- doing TCP only. Anything else belongs elsewhere.
See MessageEncoderDecoder COM, now with it's own web page at <a href="http://www.intrafoundation.com/MessageEncoderDecoder.asp">MessageEncoderDecoder</a>, for information on it.
In practice though, you'll notice many of the examples for tcpclient require MessageEncoderDecoder to be loaded to operate properly though.
</p>
<p>
Also finished the Frame functions.
</p>
</li>

<li>
<b>3.0</b> - April 3rd, 4th,7th, 8th 2004.
<p>
After debugging the thread-safe issues made a few last minute changes and decided to go ahead and change the versioning number as well.
</p>

<ol>
<li>Mulls a complete rewrite of the documentation so as to be clearer.</li>
<li>Added extended winsock error descriptions.</li>
<li>Added a Nagle sleep to Recv functions where blocking would occur. Added counters that keep track of ms sleep times for both recv and send buffers. This can allow you to track down where some underperformance issues may be on your network.</li>
</ol>
<pre class=prewrap>
<strong><tt>From: "Andrew Finkenstadt" andyf@simutronics.com<br>
Subject: RE: using TCPClient</tt></strong><br>
Well, the one thing I didn't take special note of, is whether the .Send() or<br>
.SendRN() calls were protected by a critical section, to prevent<br>
simultaneous web page access.<br>
...<br>
</pre>
<ol>
<li>
<p>Borrowed a Mutex class from another project, rewrote it and implimented a mutual exclusion mechanism.
The original design of this COM essentially assumed each instance of it would be used in isolation.
That is, when you created an instance of it, only one "user" would be using that instance at a time.
The problem with this is that collision may ocur on multi-processor systems when used in an Application wide scope.</p>
<p>Besides the mutex code, this addeds the "mutexlocks" property.</p>
</li>
<li>
Added "currentpacketsize" property.
</li>
<li>
Rebuilt interface as "Intrafoundation.Tcpclient.3".
</li>
<li>
Cleaned up UU, XX, Base64 and hex functions. (Again.)
Added new encode and decode functions and changed the way the SendFileEncoded and RecvFileEncoded (previously DecodeAsFile) functions work.
As the reworked functions now handle emitting proper headers and multiple files the reserved functions to handle attachments were removed.
(SendFileEncoded and RecvFileEncoded now do what they were originally intended to do.)
</li>
<li>Added Yenc support.</li>
<li>Added MIME support.</li>
<li>
Changed "recv_cachemisses" to "recv_packets".
Changed "send_cachemisses" to "send_packets".
Changed "buffer_cachemisses" to "recvline_faults".
</li>
<li>
Among many other things, after exploring some issues that had been bugging me for a while,
made the code a <strong>LOT</strong> less apt to long timeouts when communicating with an
open stream.
</li>
</ol>
</li>

<li>
<b>2.16</b> - March 26 - April 3rd 2004.
<p>
MAJOR update.
What started out as a simple bug fix for two issues reported at the same time (BSTR NULL's and the CSV functions) turned into a complete rewrite of a lot of the base C++ code.
So several things ended up being fixed or tweaked this go around.
There has been extensive changes to the code in places so, if you've been using this software previously,
you may wish to treat this release tentatively as a beta and double check it's operation before releasing on any production servers.
</p>
<ul>
<li><p>A new C++ "Log" class was added and the old logging routines removed and replaced with it.
The results may not be entirely obvious to the end-users beyond slightly more coherent error logging, but for anyone using the code-base itself as a core class of software that impliments a TCP/IP protocol client, this makes updating errors through the log much easier.</p></li>
<li><p>Changed name of "Clear" function to "ClearErrorLog".<p></li>
<li><p>"binarytext" class was replaced by "Base64", "UU" and "XX" classes. Also added the "Hex" class for conversion between hexadecimal formats.</p></li>
<li>
<p>
Reworked Send/SendRN/Recv/RevcRN to work with binary data (I think.)
Specifically, I added a new partial BSTR handling class that now returns the TRUE length of any strings passed to and from the COM object.
</p>
<p>
Many of you may be aware that when sending or receiving strings from COM objects they use BSTRs (Basic Strings).
BSTRs consist internally of the data string itself, an appended NULL (for C/C++ compatibility) and a prepended length counter (for BASIC compatibility).
The problem is that most every standard (Microsoft) function for returning the length of these strings returns only the length up to the first NULL it encounters
This is proper in C or C++ when dealing with standard text strings but a problem when you're sending around binary data.
</p>
<p>
To deal with this, code has been added which, as stated, returns the TRUE length of the string, including any embedded NULL's.
(Or at least, that was the intent of the changes.)
</p>
</li>
<li>
<p>Added FlushRN. The buffer for RecvRN previously would be flushed (cleared, emptied, etc) automatically anytime you called Recv but because of internal code changes it made more sense to go ahead and allow the end-user to make this call whenever they themselves saw fit.</p>
</li>
<li>
<p>Memory managment has been enhanced (tightened up) in several places.
This may boost overall performance when doing intense transfers.</p>
</li>
<li>
<p>Added "instance" and "instances" functions which returns the virtual instance number of the COM object. (See docs for explaination.)</p>
</li>
<li>
<p>Mull calling this version 3.00 instead of 2.16.</p>
</li>
<li>
<p>Added control over TCP/IP send/recv packet size via PacketSize functions.
The default is 32768 bytes.</p>
</li>
<li>
<p>Changed name of "error" to "errorlog".</p>
</li>
</ul>
<pre class=prewrap>
<strong><tt>TCPClient Author: taesachi<br>
URL: http://msdn.pe.kr<br>
Created: 9/2/2003 10:23:56 PM<br></tt></strong>
I`m Korean.<br>
This component is not supported to another language. (ex. Korean)<br>
So some change the source file.<br>
But change only Send function.<br>
<br>
Download<br>
http://msdn.pe.kr/TCPClient/tcpclientcom.zip<br>
</pre>
<p>
Fixed. (I hope. Think. As I don't read Korean, you tell me.)
</p>
<pre class=prewrap>
<strong><tt>March 26 2004</tt></strong><br>
Dear intrafoundation.com<br>
<br>
I am trying to use your tcpclientcom (which seems like a great tag the way!) but for some reason SendCSV is only sending the first byte in the list.<br>
<br>
Here's some sample code:<br>
<br>
&lt;cfset c=obj.Open("(my IP)","5300")&gt;<br>
&lt;CFIF c IS "1"&gt;<br>
     &lt;cfset obj.timeout=10.000&gt;<br>
     &lt;cfset page=obj.SendCSV("1,2,3,4,5,6,7,8,9")&gt;<br>
     &lt;CFINCLUDE TEMPLATE="obj.mod.cfm"&gt;<br>
     &lt;cfset obj.Close()&gt;<br>
&lt;/CFIF&gt;<br>
<br>
The packet sniffer on the other computer is telling me that only the "1" is being sent. Am I doing something wrong?<br>
<br>
Thanks!<br>
Shawn<br>
</pre>
<p>
Fixed.
An embarassing typo in the original code would cause this issue.
</p>
</li>

<li>
<b>2.15</b> - July 20th 2003.
<p>
Slight cleanup and rebuild.
Had to fiddle around a bit to get the Platform SDK to properly handle it.
</p>
</li>

<li>
<b>2.14</b> - September 13rd 2001.
<p>
Added PING.
</p>
</li>

<li>
<b>2.13</b> - September 3rd 2001.
<p>
Revised copyright text to clarify issues people had been asking me about.
</p>
<p>
While building UDPClient with TCPClient's project code over the weekend noticed the kbps speed functions were saying a kilo-byte was a 1,000 bytes, not 1,024 bytes as is proper. Oops. Fixed here in tcpclient as well.
</p>
</li>

<li>
<b>2.12</b> - Feb 8th 2001.
<p>
Doc, example and source clean-up.
</p>
</li>

<li>
<b>2.11</b> - Feb 3rd 2001.
<p>
2.11 consists mainly of bug fixes and performance tweaks.
In some situations 2.11 is actually 30 times faster than 2.10.
(Seriously.)
</p>
<ul>
<li>Changed internal buffer size to 32768 bytes which gives about the best LAN performance on w2k according to tests</li>
<li>Recoded the "connected" functions to be faster</li>
<li>Added 20 millisecond delay to match the Nagle alg for buffer-full sends</li>
<li>Fixed RecvRN bug that could cause a crash when remote server drops connection</li>
<li>Added experimental kilobyte-per-sec stats for send/recv</li>
</ul>
</li>

<li>
<b>2.10</b> - Feb 2nd 2001.
<p>
(Brought to you by Olivia Tremor Control.)
A few minor tweaks, including memory/speed optimizations.
In short, when doing large data transfers in the 1mb to 30mb range the tag was scaling very badly.
It threatened to crash the machine on more than one ocassion.
This has been addressed.
</p>
<p>
Oh... So, it seems the uu encode/decode functions have never worked.
Ever. :)
I originally coded them completely from memory and never tested them.
(Never needed to use them until this week.)
Of course it turns out I forgot to code for the line length markers.
Anyway... sorry about that.
Recoded base64/uu routines.
Fixed.
</p>
<ul>
<li>Added blocksize for Recv.</li>
<li>Added hascutoff indicator property.</li>
<li>Changed default tcp buffer size from 512 bytes to 8192 bytes.</li>
<li>Added several additional status properties relating to network buffer sizes.</li>
<li>Changed error log to emits CRLF's instead of &lt;BR&gt; for line ends.</li>
<li>Some misbehaving servers applications (such as Post.Office 3.5.3) have a
habit of emitting spurious NULL's after a CRLF on the mime boundries resulting
in Recv/RecvRN thinking there is no further text following.
Addressed this.</li>
<li>The UU and base64 code wasn't working properly. Fixed.</li>
<li>Send failed with a 30mb file. Reworked to send large blocks of data.</li>
</ul>
<p>
I believe it's safe to say we're probably in a feature-lock now.
There are a few undocumented or reserved functions that have yet to be implimented
(mainly SSL) but those aside the emphasis from now on is debugging and optimization.
The COM interface is locked at <em>Intrafoundation.TCPClient.1</em>.
</p>
<p>
There have been enough significant code changes to 2.10 that I'd almost thought of calling it a beta for a while.
Bit of caution here.
</p>
</li>

<li>
<b>2.9</b> - Jan 24th, 27th 2001.
<p>
After a few long emails with <strong>Bryan Owen</strong>,
the tcp class underwent an intense low-level debugging session to root out the glitches in a new caching implimentation of RecvRN.
While I was at it... there were several changes made in the fundamental tcp c++ class that's the heart of this COM object.
(For those who haven't looked, this is a C++ project with two classes: The COM object tcpclientcom itself and a class called "tcp".
The tcp class is used in several other projects, most commercial or for-hire.
This COM is used as a sort of an open-source test-bed for that critical class.)
</p>
<ul>
<li>Redid the documentation to make things <em>clearer</em>.</li>
<li>Rewrote RecvRN to give it it's own tcp-level class so as to avoid forcing tcp/ip timeouts (ie, cache misses).</li>
<li>Redid the pop3, smtp and ftp localhost tests to use RecvRN. Much smoother response time.</li>
<li>The tcp class function send wasn't properly reporting the bytes sent.</li>
<li>Several misc undocumented polishings to tcp class.</li>
<li>Fixed sticky error log. Cleared on any open now.</li>
<li>Fixed misreporting class file names.</li>
<li>Added a simple, crude little news browser. I keep tripping over the folks at <a href="http://www.fuseware.com">fuseware.com</a>. I'm sure they love me. :)</li>
</ul>
</li>

<li>
<b>2.8</b> - Jan 21st 2001.
<p>
Misc doc and script cleanup.
Changed NNTP example to forums.macromedia.com (our new overlords).
</p>
</li>

<li>
<b>2.7</b> - Jan 3rd 2001.
<p>
Misc. Polishing.
Been meaning to replace all the place holding graphics with simple (2001: Space Odyssey-ish) white plastic theme.
Small spherical indentation grids across top.
Washed out by intense white light.
Haven't had the time. Oh well.
</p>
<p>
HACKER WARNING:
The DECODEASFILE can be exploited.
Then again, this entire tag can be one big hacking exploit when in the right hands.
But, just fyi in case you were thinking otherwise.
You really shouldn't install this on a shared host.
If you have ideas on how to modify it to have a "safe" mode
(or, better yet, a conditionally compiled safe release version)
feel free to express yourself.
</p>
</li>

<li>
<b>2.6</b> - 12/24/2000.
<p>
Fixed cutoff. It was only checking when the remote server paused. Now checks after every packet.
</p>
<p>
Added RecvRN.
</p>
</li>

<li>
<b>2.5</b> - 12/21/2000.
<p>
'ello.
</p>
<p>
It was intending to <a href="http://www.gnu.org">GPL</a> this software,
but as I was preparing a formal GPL notice it occurs to me that since it prohibts inclusion in proprietary software
(which parts have already been used in and will be so again)
it can not be so.
</p>
<p>
And thus I mispoke if I said it was to be so.
</p>
<p>
Sorry.
</p>
<p>
As to what "license" this software has...
Not sure if any fit it.
For now I really don't care what you do with it as long as you give proper credit to me (name, url, etc).
I would prefer you keep it open source, but if you make significant changes you don't want to share, I understand.
The only thing that would really annoy me is if you (like one unnamed creature with 1.x) change the headers and claim you wrote it. :-)
</p>
<p>
If you develop a nice script (in your native CF or ASP VBSCRIPT, etc) that's a front-end to a protocol (POP3, FINGER, etc),
you're perfectly free to distribute the script with the COM object as long as you also include the full archive (the .zip), etc.
I also encourage you to send useful completed scripts to me for future inclusion.
</p>
<p>
You may feel free to place this in any free online component sites.
Saves me the hassle of having to do it myself.
</p>
<p>
Oh, and I changed the ClassID from TCP.Client to Intrafoundation.TCPClient.
Meant to do that earlier, before beta.
Slipped my mine.
Also fixed it so you can can use the version independant clsid "Intrafoundation.TCPClient" instead of "Intrafoundation.TCPClient.1".
</p>
<p>
Removed references to SENDSTRUCT and RECVSTRUCT.
</p>
<p>
Probably be a few other "settling" issues for a few more revisions.
This is brand new code after all.
</p>
<p>
PAX.
</p>
</li>

<li>
<b>2.4</b> - 12/21/2000.
Non-beta. Clean-up.
</li>

<li>
<b>2.3beta</b> - 12/20/2000.
First wide-beta.
Final documentation (and replacements for the little placeholding squiggles) remain.
Send in your functioning scripts for inclusion in future revisions.
BTW, as with 1.x I do essentially consider this software GPL'd.
As far as I'm concerned you can pretty much do what you want with it, as long as you don't claim you wrote it yourself. :-)
</li>

<li>
<b>2.2alpha</b> - 12/19/2000.
First documented public release.
Finished CSV functions.
Only encoding functions, datalimit implementation and final documentation remains.
Added to interface possible future additions that would support bit-level structs and SSL (Secure Socket Layer), aka HTTPS.
</li>

<li>
<b>2.1alpha</b> - 12/18/2000. First (undocumented) public release.
</li>

<li>
<b>2.0alpha</b> - 12/7/2000,  SECOND EDITION. Brand new ATL COM, written completely in C++.
This Second Edition of TCPClient competely replaces the old Allaire ColdFusion only version.
</li>

<li>
<b>1.2</b> - Nov ? 2000.
Just a repack with a different version number.
Apparently 1.1 was reporting itself as a .14beta in some places, confusing some folks.
</li>

<li>
<b>1.1</b> - 09/19,25/2000. <b>Erik Willsey</b> prompts me to make a few bug fixes.
Was already moving that way anyway as I noticed it was twitchy under W2K.
Added WAITFORSENDDATA.
Added TIMEOUT.
Fixed a few things.

<pre class=prewrap>
<strong><tt>From: Erik Willsey<br>
Sent: Tuesday, September 19, 2000 6:04 PM<br>
Subject: RE: CFX_TCPClient Bug<br></tt></strong>
I have found 4 bugs within your code regarding the WAITFORRECVDATA tag.<br>
<br>
Request.cpp - Line 334:<br>
    You have:<br>
        WaitForRecvData( s, atoi(vWaitForRecvData)*1000);<br>
    Should Be:<br>
        WaitForRecvData( s, atoi(vWaitForRecvData));<br>
<br>
You already specify that the parameter is in seconds, multiplying by 1000 greatly offsets the time.  You may have been trying to set milliseconds; which in that case, this line is not wrong, but there is misdocumentation in the guidelines.<br>
--<br>
Request.cpp - Begin @ line 234<br>
    You have:<br>
         tv.tv_sec=0;<br>
         tv.tv_usec=200;<br>
    Should be:<br>
        tv.tv_sec=secs;<br>
        tv.tv_usec=0;<br>
    Again, this depends on whether your original intention was to have seconds or milliseconds.  However, either way, the parameter for the time was not being used.  Add that into the next bug, and an infinite loop is created.<br>
--<br>
Request.cpp - Begin @ line 240<br>
    You have:<br>
        while( nosocks == 0 )<br>
        {<br>
          FD_ZERO(&readfds);<br>
          FD_SET(sock,&readfds);<br>
          nosocks=select(FD_SETSIZE,&readfds,NULL,NULL,&tv);<br>
         }<br>
    Should be:<br>
          FD_ZERO(&readfds);<br>
          FD_SET(sock,&readfds); <br>
          nosocks=select(FD_SETSIZE,&readfds,NULL,NULL,&tv);<br>
		  <br>
     Reason:  select() will return 0 when the time has elasped (it will also immediately return zero if no time has passed).  This means that if no data is ever received from the server, an infinite loop is created (well at least until the socket is closed by host or node).  By simply removing the while loop, this bug is taken care of.<br>
--<br>
Request.cpp - Begin @ line 247<br>
       The remainder of that method should reside within an if statement checking that "nosocks" is not zero.  "nosocks" will only be zero if the time elapsed.  By jumping into the while loop retrieving the data, another infinite loop is created, because recv() will always return 0 if there is no data in the socket's buffer.<br>
<br>
I hope this helps you some.  You've written a great tag.<br>
Thanks,<br>
Erik Willsey<br>
Blitz Programming<br>
</pre>
</li>

<li><b>1.0gamma</b> - 09/1/2000. The ancient beast awakes. Fixed a bug....</li>

<li><b>0.15beta</b> - 02/17/2000. Doc tweak.</li>

<li><b>0.14beta</b> - 02/11/2000.
Bug report by <b>Jonathan</b>. No, besides that there have been no changes since the last version. However... a bit of work in a week might require something similiar so some advances might be made. If I know where the problems are. Send in feedback. Feature requests, etc.
<pre class=prewrap>
<strong><tt>Sent: Friday, February 11, 2000 12:51 PM<br>
Subject: cfx_tcpclient bug fix<br></tt></strong>
When I get " RECV Error - no response for %lds %lums "<br>
(i.e. no more data to read) the recv CF variable will have<br>
random crap in it since SocketRecv never appends<br>
a NULL to recvp.  So when SetVariable is called, it<br>
copies memory from recvp's address until it does find<br>
a NULL--somewhere else.  Obviously this will cause problems<br>
with some recv loops unless you code around it. :)<br>
<br>
I fixed this by adding<br>
*recvp=0;<br>
after<br>
recvp=(char *)malloc(1);<br>
in SocketRecv() in Request.cpp.<br>
<br>
Thanks for the code! :)<br>
<br>
-Jonathan<br>
</pre>
</li>

<li><b>0.13beta</b> - 01/07/2000. misc. examples & docs changes.
contemplation of optional restriction security mode against *FILE functions and option to list ALLOWED ports (those not being listed, being those DENIED).
</li>

<li><b>0.12beta</b> - 01/04/2000.
Spawned project to CFX_TCPServer and removed all SERVER/LISTEN code.
Went over project.
Everything seems to work. More or less.
Back to beta status.
If you need IDENT for IRC protocol now you'll have to also install CFX_TCPServer when I finish it.
</li>

<li><b>0.12alpha</b> - 01/04/2000.
ENCODING functions finished. work now.
Only LISTEN/ACCEPT code, and code/example/doc polishing remain.
Some socket functions <cite>getsockname</cite>, etc are experiencing long timeouts sporatically if local DNS is overburdened.
Will fix.
<li><b>0.11alpha</b> - 01/04/2000.
LISTEN and ENCODING function may not currently work at all and are in an ALPHA state.
The CSV functions are slugs that need to be retooled at a lower level.
Everything else should be BETA and working as far as I know.
This somewhat premature release is so people can do further testing on the new "engine".
Have fun.
Next release should be full beta.
Might get a chance to do that in 3 or 4 days.
</li>

<li><b>0.10alpha</b> - 01/02/2000. not released to public.
massive code rewrite.
added csv SENDBINARYCSV and RECVBINARYCSV.
removed temp internal 256k data limit.
misc, etc.
This version is possibly very unstable compared to the previous because of the massive rewrite. but very much more useful. caution.
It can at least do PASV ftp to get file listings, etc now.
the mime/uu/xx code hasn't really been tested. Mostly just typed it in from memory of the theory.
It does compile without error though.
so.... /-)
I need to clean the mime/uu/xx up and then fix it so the tag can listen at a tcp port for full ftp, etc functionality.
(ie, OPENSERVER and CLOSESERVER don't work yet.)
I'm mulling over what to do with SENDFILE and RECVFILE to make the tag safer....
The tag goes back to <em>alpha</em> status for 0.10 because of an aggressive rewriting session last night that leaves much of the tag in an unstable state.
However... several interesting new abilities are almost available now. Read the history.
</li>

<li><b>0.9beta</b> - 12/27/1999. misc. If I have time I'll try to debug all the BINARY stuff by next time and add in a working binary ftp example. Someone want to do a vt100 telnet client? /-)</li>
<li><b>0.8beta</b> - 12/22/1999. minor tweaks.</li>

<li><b>0.7beta</b> - 12/22/1999. waiting for feedback before much else gets done. yawn.... spawned off a copy of the project for CFX_UDPClient. Back to paying work. If you ever want to see a .8, then send <em><strong>feedback</strong></em>. :)
This tag is still under development, but coming close to being stable.
If you have feedback or want to donate* a cfm example for communicating with a certain TCP server type, then feel free.
<small>*Especially those that say "under development" such as telnet, or qotd etc.</small><br>
</li>

<li><b>0.6beta</b> - 12/21/1999. first mostly stable release. essential feature-lock. donate working examples please so I can test the stability, especially those involving binary transfers. also ip's for public qotd, echo, etc sites would be nice.</li>
<li><b>0.0alpha</b> to <b>0.5alpha</b> - 12/20/1999-12/21/1999. Seriously began work on it again partially to understand TCP/UDP for linux-based network-related project. And because it was fun.</li>
<li><b>0.0</b> - 5/1999 made the project file. abandoned a few seconds later.</li>

</ul>
<!-- END DESCRIPTION -->


<br clear=all>
<hr>
<div align=right>
Intrafoundation Software<br>
<small><tt>Making Atomic Warfare Fun Again</tt></small><br>
<br clear=all>
</div>


</body>
</html>

