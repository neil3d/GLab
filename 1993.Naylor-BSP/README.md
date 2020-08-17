# Constructing Good Partitioning Trees

- Author: Bruce Naylor
- Publication: Graphics Interface '93

## 更早期的相关文章

- [On visible surface generation by a priori tree structures](./800250.807481.pdf)
    - Authors: Henry Fuchs, Zvi Meir Kedem, B. F. Naylor
    - Publication: SIGGRAPH '80
    - https://dl.acm.org/doi/10.1145/800250.807481

 ## 3D 引擎相关

 - 在 Wolfenstein, DOOM、Quake 等早期基于软件渲染的 3D 引擎中，基本都用到了 BSP 技术

> John started searching around for 3D research papers. He had several VHS tapes of math conferences, and compendiums of graphics papers from conferences because game books were a rare thing back then, and there was nothing printed that could help us create the engine we were building – he had to figure out where to get information that was not directly applicable to games and figure out how to adapt it to his problem.  
> Bruce Naylor’s May 1993 AT&T Bell Labs paper was titled "Constructing Good Partitioning Trees" and was published in the proceedings of Graphics Interface ’93. John had this book in his collection. Bruce’s explanation of BSPs was mostly to cull backfaces from 3D models, but the algorithm seemed like the right direction, so John adapted it for Wolfenstein 3D.  
> — John Romero


> I do remember clearly that I first used BSP for the SNES version of Wolfen- stein, which was a gentle introduction with everything being axial and easier to visualize, which gave me more confidence I would be able to make it work when I went back to working on Doom.
> — John Carmack


> When I did the early work on BSPs, Bruce Naylor came down and visited here and gave me copies of a bunch of his papers. It’s interesting to talk to people about the old days. Of course, you’ve got the Internet now. You can find anything nowadays. But back then, it was really something to get reprints of old academic papers. There were some clearinghouses I used to use: you’d pay twenty-five dollars or whatever, and they’d mail you xeroxes of old research papers. It was just a very, very different world. I learned most of my programming when I had a grand total of like three reference books. You had to figure everything else yourself. So I was finding I was reinventing a lot of classic things, like Huffman encoding or LZW encoding. So I’d be all proud of myself for having figured something out, and then I’d find it was just classic method and they did it better than I did.  
> — John Carmack, Interview for Scarydarkfast


- Fabien Sanglard,[Game Engine Black Book: Doom](https://github.com/fabiensanglard/gebbdoom), Chapter 5.12 3D Renderer