# Macro Parser Explained

## Explanation without Colors

For this explanation, `${Me.Name}` will return "Knightly" and `${Me.Class}` will return "Programancer."  I'm also going to reference the Spawn ID of Knightly with `${Spawn[=Knightly].ID}` returning "007" even though this is meaningless outside of the context of this explanation.

**The MacroQuest parser first parses from left to right to tokenize the variables that need to be parsed.  That means in the command:**

```txt
/echo My name is ${Me.Name} and my class is ${Me.Class}.
```

MacroQuest first parses `${Me.Name}` so that the above becomes:

```txt
My name is Knightly and my class is ${Me.Class}.
```

And then parses `${Me.Class}` so that the above returns:

```txt
[MQ2] My name is Knightly and my class is Programancer.
```

**Nested queries are processed from right to left AFTER it has been tokenized.  What this means is that in:**

```txt
/echo My ID is ${Spawn[=${Me.Name}].ID} and my class is ${Me.Class}.
```

MacroQuest first tokenizes to get `${Spawn[=${Me.Name}].ID}` and then parses `${Me.Name}` becoming:

```txt
My ID is ${Spawn[=Knightly].ID} and my class is ${Me.Class}.
```

Since there are still items to parse it continues to the left to get:

```txt
My ID is 007 and my class is ${Me.Class}.
```

And finally returns:

```txt
[MQ2] My ID is 007 and my class is Programancer
```

**The exception to this is when you override the parser with the `${Parse[]}` functionality.  This tells the parser to "START HERE" on any tokenized string.  The outermost Parse function always wins.  The number after the brace tells the Parse override how many times to iterate.  This means in the command:**

```txt
/echo My ID is ${Parse[0,${Spawn[=${Me.Name}].ID}]} and my class is ${Me.Class}.
```

MacroQuest first tokenizes to get `${Parse[0,${Spawn[=${Me.Name}].ID}]}` and, because there is a  `${Parse[]}` that gets evaluated first.  In this case, the parse is 0 which means "do not parse" so this becomes:

```txt
My ID is ${Spawn[=${Me.Name}].ID} and my class is ${Me.Class}.
```

And MacroQuest moves on to evaluating the `${Me.Class}` token to output:

```txt
[MQ2] My ID is ${Spawn[=${Me.Name}].ID} and my class is Programancer.
```

**You can use this to stop the parsing after one iteration:**

```txt
/echo My ID is ${Parse[1,${Spawn[=${Me.Name}].ID}]} and my class is ${Me.Class}.
```

MacroQuest first tokenizes to get `${Parse[1,${Spawn[=${Me.Name}].ID}]}` and because there is a `${Parse[]}` that gets evaluated first.  In this case, the parse is 1 which means "parse one time" so this becomes:

```txt
My ID is ${Parse[0,${Spawn[=Knightly].ID}]} and my class is ${Me.Class}.
```

Which then becomes:

```txt
My ID is ${Spawn[=Knightly].ID} and my class is ${Me.Class}.
```

And MacroQuest moves on to evaluating the `${Me.Class}` token to output:

```txt
[MQ2] My ID is ${Spawn[=Knightly].ID} and my class is Programancer.
```

**Setting this to higher numbers allows you to iterate as many times as necessary, but each iteration only parses the innermost variable.  That means, too many iterations will end up as if you hadn't used `${Parse[]}` at all.  In this same scenario consider if we used 2 iterations:**

```txt
/echo My ID is ${Parse[2,${Spawn[=${Me.Name}].ID}]} and my class is ${Me.Class}.
```

Again, starting with the first token `${Parse[2,${Spawn[=${Me.Name}].ID}]}` the line becomes:

```txt
My ID is ${Parse[1,${Spawn[=Knightly].ID}]} and my class is ${Me.Class}.
```

And then the next iteration it becomes:

```txt
My ID is ${Parse[0,007]} and my class is ${Me.Class}.
```

And then:

```txt
My ID is 007 and my class is ${Me.Class}.
```

Until, finally, the Parse section is done and the parser moves on to `${Me.Class}` and outputs:

```txt
[MQ2] My ID is 007 and my class is Programancer.
```

So you can see that in this case `${Parse[2,${Spawn[=${Me.Name}].ID}]}` and `${Spawn[=${Me.Name}].ID}` are functionally equivalent.

**Parse priority is also true for NESTED parses, so the outermost parse gets evaluated first and the action on that determines how the inner parses will get handled.  Consider for example:**

```txt
/echo This test is ${Parse[0,${Parse[1,${Me.Name}]}]}.
```

Which will return:

```txt
[MQ2] This test is ${Parse[1,${Me.Name}]}.
```

Changing the first 0 to a 1 to make the command:

```txt
/echo This test is ${Parse[1,${Parse[1,${Me.Name}]}]}.
```

Will become:

```txt
This test is ${Parse[0,${Parse[0,Knightly]}]}.
```

Which will return:

```txt
[MQ2] This test is ${Parse[0,Knightly]}
```

Finally, swapping the 0 and 1 from the first command will make the command:

```txt
/echo This test is ${Parse[1,${Parse[0,${Me.Name}]}]}.
```

Which will become:

```txt
This test is ${Parse[0,${Me.Name}]}.
```

And then output:

```txt
[MQ2] This test is ${Me.Name}
```

## Explanation Colorized (requires LaTeX viewer)

For this explanation, $`\textcolor{teal}{\text{\$\{Me.Name\}}}`$ will return "$`\textcolor{teal}{\text{Knightly}}`$" and $`\textcolor{green}{\text{\$\{Me.Class\}}}`$ will return "$`\textcolor{green}{\text{Programancer}}`$."  I'm also going to reference the Spawn ID of Knightly with $`\textcolor{purple}{\text{\$\{Spawn[=Knightly].ID\}}}`$ returning "$`\textcolor{purple}{\text{007}}`$" even though this is meaningless outside of the context of this explanation.

**The MacroQuest parser first parses from left to right to tokenize the variables that need to be parsed.  That means in the command:**

`/echo My name is `$`\textcolor{teal}{\text{\$\{Me.Name\}}}`$` and my class is `$`\textcolor{green}{\text{\$\{Me.Class\}}}`$`.`

MacroQuest first parses $`\textcolor{teal}{\text{\$\{Me.Name\}}}`$ so that the above becomes:

`My name is `$`\textcolor{teal}{\text{Knightly}}`$` and my class is `$`\textcolor{green}{\text{\$\{Me.Class\}}}`$`.`

And then parses $`\textcolor{green}{\text{\$\{Me.Class\}}}`$ so that the above returns:

```txt
[MQ2] My name is Knightly and my class is Programancer.
```

**Nested queries are processed from right to left AFTER it has been tokenized.  What this means is that in:**

`/echo My ID is `$`\textcolor{purple}{\text{\$\{Spawn[=}}`$$`\textcolor{teal}{\text{\$\{Me.Name\}}}`$$`\textcolor{purple}{\text{].ID\}}}`$` and my class is `$`\textcolor{green}{\text{\$\{Me.Class\}}}`$`.`

MacroQuest first tokenizes to get $`\textcolor{purple}{\text{\$\{Spawn[=}}`$$`\textcolor{teal}{\text{\$\{Me.Name\}}}`$$`\textcolor{purple}{\text{].ID\}}}`$ and then parses $`\textcolor{teal}{\text{\$\{Me.Name\}}}`$ becoming:

`My ID is `$`\textcolor{purple}{\text{\$\{Spawn[=}}`$$`\textcolor{teal}{\text{Knightly}}`$$`\textcolor{purple}{\text{].ID\}}}`$` and my class is `$`\textcolor{green}{\text{\$\{Me.Class\}}}`$`.`

Since there are still items to parse it continues to the left to get:

`My ID is `$`\textcolor{purple}{\text{007}}`$` and my class is `$`\textcolor{green}{\text{\$\{Me.Class\}}}`$`.`

  And finally returns:

```txt
[MQ2] My ID is 007 and my class is Programancer
```

**The exception to this is when you override the parser with the $`\textcolor{red}{\text{\$\{Parse[]\}}}`$ functionality.  This tells the parser to "START HERE" on any tokenized string.  The outermost Parse function always wins.  The number after the brace tells the Parse override how many times to iterate.  This means in the command:**

`/echo My ID is `$`\textcolor{red}{\text{\$\{Parse[0,}}`$$`\textcolor{purple}{\text{\$\{Spawn[=}}`$$`\textcolor{teal}{\text{\$\{Me.Name\}}}`$$`\textcolor{purple}{\text{].ID\}}}`$$`\textcolor{red}{\text{]\}}}`$` and my class is `$`\textcolor{green}{\text{\$\{Me.Class\}}}`$`.`

MacroQuest first tokenizes to get $`\textcolor{red}{\text{\$\{Parse[0,}}`$$`\textcolor{purple}{\text{\$\{Spawn[=}}`$$`\textcolor{teal}{\text{\$\{Me.Name\}}}`$$`\textcolor{purple}{\text{].ID\}}}`$$`\textcolor{red}{\text{]\}}}`$ and, because there is a $`\textcolor{red}{\text{\$\{Parse[]\}}}`$ that gets evaluated first.  In this case, the parse is 0 which means "do not parse" so this becomes:

`My ID is `$`\textcolor{red}{\text{\$\{Spawn[=\$\{Me.Name\}].ID\}}}`$` and my class is `$`\textcolor{green}{\text{\$\{Me.Class\}}}`$`.`

And MacroQuest moves on to evaluating the $`\textcolor{green}{\text{\$\{Me.Class\}}}`$ token to output:

```txt
[MQ2] My ID is ${Spawn[=${Me.Name}].ID} and my class is Programancer.
```

**You can use this to stop the parsing after one iteration:**

`/echo My ID is `$`\textcolor{red}{\text{\$\{Parse[1,}}`$$`\textcolor{purple}{\text{\$\{Spawn[=}}`$$`\textcolor{teal}{\text{\$\{Me.Name\}}}`$$`\textcolor{purple}{\text{].ID\}}}`$$`\textcolor{red}{\text{]\}}}`$` and my class is `$`\textcolor{green}{\text{\$\{Me.Class\}}}`$`.`

MacroQuest first tokenizes to get $`\textcolor{red}{\text{\$\{Parse[1,}}`$$`\textcolor{purple}{\text{\$\{Spawn[=}}`$$`\textcolor{teal}{\text{\$\{Me.Name\}}}`$$`\textcolor{purple}{\text{].ID\}}}`$$`\textcolor{red}{\text{]\}}}`$ and because there is a $`\textcolor{red}{\text{\$\{Parse[]\}}}`$ that gets evaluated first.  In this case, the parse is 1 which means "parse one time" so this becomes:

`My ID is `$`\textcolor{red}{\text{\$\{Parse[1,}}`$$`\textcolor{purple}{\text{\$\{Spawn[=}}`$$`\textcolor{teal}{\text{Knightly}}`$$`\textcolor{purple}{\text{].ID\}}}`$$`\textcolor{red}{\text{]\}}}`$` and my class is `$`\textcolor{green}{\text{\$\{Me.Class\}}}`$`.`

Which then becomes:

My ID is $`\textcolor{red}{\text{\$\{Spawn[=Knightly].ID\}\}}}`$` and my class is `$`\textcolor{green}{\text{\$\{Me.Class\}}}`$`.`

And MacroQuest moves on to evaluating the $`\textcolor{green}{\text{\$\{Me.Class\}}}`$ token to output:

```txt
[MQ2] My ID is ${Spawn[=Knightly].ID} and my class is Programancer.
```

**Setting this to higher numbers allows you to iterate as many times as necessary, but each iteration only parses the innermost variable.  That means, too many iterations will end up as if you hadn't used $`\textcolor{red}{\text{\$\{Parse[]\}}}`$ at all.  In this same scenario consider if we used 2 iterations:**

`/echo My ID is `$`\textcolor{red}{\text{\$\{Parse[2,}}`$$`\textcolor{purple}{\text{\$\{Spawn[=}}`$$`\textcolor{teal}{\text{\$\{Me.Name\}}}`$$`\textcolor{purple}{\text{].ID\}}}`$$`\textcolor{red}{\text{]\}}}`$` and my class is `$`\textcolor{green}{\text{\$\{Me.Class\}}}`$`.`

Again, starting with the first token $`\textcolor{red}{\text{\$\{Parse[2,}}`$$`\textcolor{purple}{\text{\$\{Spawn[=}}`$$`\textcolor{teal}{\text{\$\{Me.Name\}}}`$$`\textcolor{purple}{\text{].ID\}}}`$$`\textcolor{red}{\text{]\}}}`$ the line becomes:

`My ID is `$`\textcolor{red}{\text{\$\{Parse[1,}}`$$`\textcolor{purple}{\text{\$\{Spawn[=}}`$$`\textcolor{teal}{\text{Knightly}}`$$`\textcolor{purple}{\text{].ID\}}}`$$`\textcolor{red}{\text{]\}}}`$` and my class is `$`\textcolor{green}{\text{\$\{Me.Class\}}}`$`.`

And then the next iteration it becomes:

`My ID is `$`\textcolor{red}{\text{\$\{Parse[0,}}`$$`\textcolor{purple}{\text{007}}`$$`\textcolor{red}{\text{]\}}}`$` and my class is `$`\textcolor{green}{\text{\$\{Me.Class\}}}`$`.`

And then:

`My ID is `$`\textcolor{purple}{\text{007}}`$` and my class is `$`\textcolor{green}{\text{\$\{Me.Class\}}}`$`.`

Until, finally, the Parse section is done and the parser moves on to $`\textcolor{green}{\text{\$\{Me.Class\}}}`$ and outputs:

```txt
[MQ2] My ID is 007 and my class is Programancer.
```

So you can see that in this case $`\textcolor{red}{\text{\$\{Parse[2,}}`$$`\textcolor{purple}{\text{\$\{Spawn[=}}`$$`\textcolor{teal}{\text{\$\{Me.Name\}}}`$$`\textcolor{purple}{\text{].ID\}}}`$$`\textcolor{red}{\text{]\}}}`$ and $`\textcolor{purple}{\text{\$\{Spawn[=}}`$$`\textcolor{teal}{\text{\$\{Me.Name\}}}`$$`\textcolor{purple}{\text{].ID\}}}`$ are functionally equivalent.

**Parse priority is also true for NESTED parses, so the outermost parse gets evaluated first and the action on that determines how the inner parses will get handled.  Consider for example:**

`/echo This test is `$`\textcolor{orange}{\text{\$\{Parse[0,}}`$$`\textcolor{red}{\text{\$\{Parse[1,}}`$$`\textcolor{teal}{\text{\$\{Me.Name\}}}`$$`\textcolor{red}{\text{]\}}}`$$`\textcolor{orange}{\text{]\}}}`$`.`


Which will return:

```txt
[MQ2] This test is ${Parse[1,${Me.Name}]}.
```

Changing the first 0 to a 1 to make the command:

`/echo This test is `$`\textcolor{orange}{\text{\$\{Parse[1,}}`$$`\textcolor{red}{\text{\$\{Parse[1,}}`$$`\textcolor{teal}{\text{\$\{Me.Name\}}}`$$`\textcolor{red}{\text{]\}}}`$$`\textcolor{orange}{\text{]\}}}`$`.`

Will become:

`This test is `$`\textcolor{orange}{\text{\$\{Parse[0,}}`$$`\textcolor{red}{\text{\$\{Parse[0,}}`$$`\textcolor{teal}{\text{Knightly}}`$$`\textcolor{red}{\text{]\}}}`$$`\textcolor{orange}{\text{]\}}}`$`.`

Which will return:

```txt
[MQ2] This test is ${Parse[0,Knightly]}
```

Finally, swapping the 0 and 1 from the first command will make the command:

`/echo This test is `$`\textcolor{orange}{\text{\$\{Parse[1,}}`$$`\textcolor{red}{\text{\$\{Parse[0,}}`$$`\textcolor{teal}{\text{\$\{Me.Name\}}}`$$`\textcolor{red}{\text{]\}}}`$$`\textcolor{orange}{\text{]\}}}`$`.`

Which will become:

`This test is `$`\textcolor{red}{\text{\$\{Parse[0,}}`$$`\textcolor{teal}{\text{\$\{Me.Name\}}}`$$`\textcolor{red}{\text{]\}}}`$`.`

And then output:

```txt
[MQ2] This test is ${Me.Name}
```