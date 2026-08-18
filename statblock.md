# Statblock
## What is?
Statblocks represent an "Entity" ─ this word basically means: anything ─ mechanically. It retains important information about that entity. As examples: HP commonly represents an entity's resistance and will to stay alive, or Damage means how much damage that entity can cause.

Statblocks are composed of **stats**, and each stat has a type. For example: Hit Points (Points Type), Strength (Ability Score Type), and many others... It could be for an item, monster, NPC, player character, or anything else you want.

**Examples:**
* *a Player Character statblock could have six stats from the Ability Scores type (Strength, Dexterity, Constitution, Intelligence, Wisdom and Charisma), HP and Mana from the Points type, Defense and Damage, and more in a Medieval Fantasy Scenario*
* *a simple item could contain just Durability from the Points type*
* *a Monster will probably have most of the Player Character features*

**With statblocks you can...**
* use a ready template (less customization, but faster and easier)
* create your own stats based on types (probably will serve most cases)
* manage every type of info to create a custom statblock (more specific cases; also, if you want to contribute, I can evaluate putting it into the framework)

## Stat Types
### Ability Score (struct abilityScore)
Ability Scores represent some basic capacity of an entity. Mainly, its mechanical effects are on (passive or common) "Skill Checks" (see more in adventure.md).

With this function you can create new ability score types, such as Strength, Perseverance or Mind. Give it a name for whatever you wish.

#### Creation:
When creating an element of type abilityScore, you'll need to type:

abilityScore *name* (*_viewName*, *_minValue*, *_maxValue*, *_startingValue*)

* *_viewName*: Name that will be shown when referenced in other UI.
* *_minValue*: Minimum value. The actual value can't be lower than this.
* *_maxValue*: Maximum value. The actual value can't be higher than this.
* *_startingValue*: The starting value of the ability score.

#### Functions:
* **set(_newValue)**: sets the actual value to *_newValue*.

### Points (struct points)
Points can represent many, many things! But the major use is for "entities that can run out". Some very common examples in RPG games are:

* **Hit Points:** usually represent a character's resistance and will to live
* **Mana Points:** represent a character's mana, used to cast spells
* **Durability Points:** represent the wear of equipment

**Note:** In the first testing versions, this resource and its functions may only accept integer values.

### Creation:
When creating an element of type points, you'll need to type:

points *name* (*_viewName*, *_maxPoints*, *_startingValue*, *_minimumPoints*, *_runOutEvent*)

* *_viewName*: Name that will be shown when referenced in other UI.
* *_maxPoints*: Maximum points. The actual points cannot exceed the maximum points.
* *_startingValue*: The starting amount of points.
* *_minimumPoints*: Minimum points. If actual points go below this value, it will trigger the run out event.
* *_runOutEvent*: Integer value. Depending on the value, different events may occur. *Ex: 1 = Death, 2 = Break Item*...

### Functions:
* **damage(_damage)**: reduces the actual points by *_damage*. If this damage would take the actual points below the minimum number of points, the run out event is triggered.
* **heal(_heal)**: increases the actual points by *_heal*. If this heal would take the actual points above the maximum number of points, it just keeps them at the maximum.