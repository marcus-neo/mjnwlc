Individual Reflection
=====================

Imperial Login : wlc3317

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

The advantage our group had was that we were living in the same house, making discussions extremely convenient and conducive. To ensure we were both on the same level of understanding, we always worked on the project together at the same time. We implemented exhaustive checklists to update each other on our progress and acted as a vetting platform for each other to look through the coherence of our codes. Having just learnt the basics of object-oriented programming, we decided to implement the architectural components as different classes for enhanced clarity. This minimised confusion during testing and debugging.


Time management
---------------

Our group had a methodical plan right from the start regarding milestones throughout the duration of the coursework. We utilised time efficiently by working independently so there would be no conflict in code implementation. I took on the role of the lead coder as I was able to come up with working prototypes in a relatively short period of time without many bugs. With my efficiency and with Marcus setting the daily pace, we managed to implement all but two functions by the formative assessment deadline, leaving us with minimal debugging and testing for the final submission deadline.


Software skills (e.g. debugging, design, coding)
------------------------------------------------

At the start, I primarily worked on the memory map of the simulator. Due to the large size of the memory block, I experimented with maps and vectors before settling on arrays to optimise speed. I also worked on building all the instructions from scratch. Ensuring that instructions covered all edge cases and threw the correct exceptions was hard to conceptualise. Pinpointing bugs to the simulator or the binary was tedious as well. This led me to resort to manual calculations to test for anomalies for certain test cases. Towards the end, I cleaned up the code for better readability.


Tools and Infrastructure (e.g. OS, automation, ...)
---------------------------------------------------

To ensure compatibility, our group decided to do all testing on an Ubuntu terminal of Marcus’ laptop. Upon hindsight, we should also have utilised my laptop so that testing of the instruction functionality in the simulator and the testbench test cases could be more efficient. Building scripts were foreign to us and hindered automated testing in the beginning. Due to the usage of three different OS (Windows, Linux, Mac) and three different languages (C++, Bash, ExcelVBA), we had to figure out ways to bridge the simulator and the testbench by installing tools such as dos2unix to convert text files.


Understanding of computer architecture
--------------------------------------

Having learnt Assembly in first year, I inadvertently implemented the instructions as what I had been familiar with. After many failed tests, I realised I did not fully understand the differences that the MIPS instruction set had to offer, so I took a step back to carefully analyse the ISA and go through different edge cases. Designing each component of the architecture as different files also gave me a better perspective of how these various components work together to transmit and receive information. This helped me to appreciate the intricacies of what happens beneath all the elegant high-level programming.
