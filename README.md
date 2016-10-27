# QtNiCanConsole

This application is a console application that will allow you to interface with the NI-8473 CAN box.  The QT based application shows messages that are received and allows you to send generic CAN messages you construct.  This allows you to easily test other CAN nodes for operation.

*NOTES:
1. Assumes the environment variables NIEXTCCOMPILERSUPP is set.  This should happen if you have installed the required libraries if not then you can point it to C:\Program Files (x86)\National Instruments\Shared\ExternalCompilerSupport\C\

Feature Requests:
- Freeze output window
- Show raw message or filtered
- Ability to apply filters to log and output window
- Error windows
