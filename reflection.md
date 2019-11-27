Individual Reflection
=====================

Imperial Login : mjn18

Group Name : Lelolulalil

Guidance
--------

The aim is to get you to think about specific things that you
have learnt, or things that went well or less well. For each
of the areas identified below, write (at most) 100 words on how
well that area went. Examples of things that you might address
are:

- Some kind of concept or approach that became clearer

- A skill or tool that you found useful

- Identifying where some choices were poor

- A change in approach that improved your solution

- Changes in strategy that could help in future projects

You may find it difficult to capture things in 100 words,
and this is part of the challenge - communication is
an important part of engineering, and it is important to
be able to condense and summarise things. If a section
is more than 100 words, then the result will be linearly
scaled such that at 200 words or more the mark drops to zero.

You should identify things specific to you and this coursework,
not just general things, and link them to specific features or
activities of the coursework. In some cases you may want to refer
to classes, functions, or source files in your submission,
and/or highlight specific commits (e.g. by hash) in order to
show changes.

For example, these are quite generic and don't tell us anything:

> I learnt how to use classes more effectively.

> I hadn't used the command line much before, and now have got used to it.

Whereas these are more specific (don't use these as a template, you
have to use your own words):

> Originally I wasn't sure how to map part A of the simulator into
> structs, so I originally thought about mapping each B to an
> struct. However, this turned out to be the wrong approach
> because C, so we ended up using D.

> I suggested that we use method A to build the testbench, as I
> thought it would have benefit B. While it worked well enough,
> in future I might choose to do C, because D. 

There is no "right" answer, and there is no particular
requirement on how "big" each thing is, either in concept
size or the number of words. There is also no bias towards
whether a strength or weakness is better - either could be
relevant. The only requirements are that the answers should be:

- Specific to you

- Specific to this coursework

- Be some sort of genuine reflection on your practise

- Related to the specific topic

This will be assessed, and is not just a tick box exercise.

Submission
----------

This should be submitted individually via blackboard (not
via the group repo).

Group working
-------------
Understanding that pair-work projects could spell overlaps in 
responsibilities when handled poorly, we agreed to start from 
opposite ends and meet halfway. I created the simulator’s 
structural logic. Once I was done with that, Wei Loon would 
start on the instruction and memory logic, while I moved on 
to work on the testbench. When Wei Loon was done with his part, 
he would then help to generate test cases for the load and store 
instructions. This method proved to be really effective as there 
were minimal overlaps. The only waiting time was for me to complete 
the simulator’s structural logic.

(up to 100 words)


Time management
---------------
Despite this project being six weeks long, the Vector Calculus test 
between the formative assessment and the final submission that 
created headaches for Wei Loon and I in terms of time management. 
Nonetheless, we still managed our time decently. Being a person who 
does not enjoy leaving things to the last minute, I led the overall 
pace of the project. I ensured we had ample time left to upgrade our 
project before the respective deadlines instead of rushing to finish 
till the last second. This, together with Wei Loon’s efficient 
workstyle, made us complete the project with sufficient time remaining.

(up to 100 words)


Software skills (e.g. debugging, design, coding)
------------------------------------------------
I designed the simulator’s structural logic (reading, decoding and 
linking the binary to the corresponding function). Despite just learning 
object-oriented programming, I used OOP to categorize functions better. 
In retrospect, this choice was right. Though the OOP was basic, Wei Loon 
had little confusion working on the instruction and memory logic, therefore 
saving us time.

I was responsible for creating the testbench and over two hundred tests. I 
initially had difficulty implementing the bash script as its syntax was confusing. 
After much patience and determination, I successfully iterated through binary 
files and produced output files to match the answer files.

(up to 100 words)


Tools and Infrastructure (e.g. OS, automation, ...)
---------------------------------------------------
Initially, I used visual studio code for the simulator. However, there were 
constant problems when Wei Loon tried executing it on his MacBook. Hence, I 
switched to Ubuntu app on Windows to prevent further issues. If we had done 
that earlier, we would have saved much more time.

I worked on the generation of the testbench and test codes because of my 
Excel VBA proficiency. Instead of using third-party software, I decided to 
create my own automation process with VBA. This enabled swift translation 
from instructions into binaries, which saved loads of time compared to 
manually creating hundreds of testbenches.

(up to 100 words)


Understanding of computer architecture
--------------------------------------
By using OOP to simulate each hardware block in the MIPS architecture like 
the registers, memory and ALU, I learnt about the interactions between these 
hardware blocks when instructions are called.

By creating my own testbench automation process with Excel VBA, I learnt 
in-depth about the bit distributions and bit positions of registers codes, 
op-codes, addresses, immediate and function codes for r-type, i-type and j-type 
instructions.

Furthermore, with the creation of the tests, I learnt about the importance of 
delay slots and how they would generate completely different answers for branch 
and jump tests if not correctly taken into consideration.

(up to 100 words)
