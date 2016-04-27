# Check-Brackets-Match-in-Text
A c++ file that can check if there is any bracket usage error in the input text. Bracket usage error here means the there exists at least one unmatched bracket. For example, '[' in "eat fruit(apple)[ every day" is unmatched since there is no ']' after '['.
***
There are two cases to be checked here:
<p>
  1. find the first unmatched closing bracket (either no opening bracket before it or closes the wrong opeing bracket like ] in ()] and ) in {[)}  )
  2. if no case 1, then find the first unmatched opening bracket without corresponding closing bracket after it, like [ in {()[}
<p> If there are no abovementioned mistakes, the bracket usage is correct
