# AsciiGameEngine
Project History - July 2010

This was one of my first big projects, and I'm still a little dumbfounded that I managed to pull this much off after some 6 months of programming experience. Some of the more interesting features this engine sports are a command line based input, and loading maps from bin files, with easily the most interesting feature being the message box which is capable of doing logical word wrapping, text coloring via tags, and supporting messages longer than the message box could display.

To go into more detail with the message box:
* Logical word wrapping: This would wrap the full word, rather than wrap mid word, by moving to the right most extreme and stepping backwards until either A) It encountered a space or B) it stepped back more than half the message box width, after which it would give up and just split the word.
* Text coloring: The user would supply a default color for all text and then use tags in the form of `$<HalfRed>` or `$<HR>` to change the color to the console's dark red color. The user could then use the tag `$<default>` or `$<dflt>` to return it to the default specified color. This was done by parsing the tags and changing the output color accordingly.
* Long messages: When the message was found to be longer than the box could display, the word `<Enter>` would be displayed at the bottom with two flashing, downward pointing arrows, and wait for the user to press enter before displaying the next field of text. This would repeat as many times as would be needed until the end of the message was encountered.

Demonstration video (Level Editor):<br>
https://www.youtube.com/watch?v=icsvozg117A

Demonstration video (Game):<br>
https://www.youtube.com/watch?v=6MjfnAkBzrI
