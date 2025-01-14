# UE5 Dialog Manager Plugin

## Overview
The UE5-Dialog-Manager Plugin is a flexible dialog system.

## Features
* Customizable conversations and player response handling
* Data Tables for storing dialog line details, including speaker name, player responses, and audio clip
* Dialog UI widget
* Example player controller blueprint and npc with dialog component attached, demonstrating possible implementation ideas

## Requirements
* Unreal Engine 5.4 or later
* Visual Studio 2019 or 2022 setup for Unreal Engine development

## How to install
1. Add the plugin to your existing UE5 project into the Plugins folder (create one if it does not yet exist). The zip can be downloaded or this repo can be added as a submodule in your project.
2. Right-click your project's .uproject file and select "Generate Visual Studio project files"
3. Open the Visual Studio solution and build the project

## Using the Dialog Manager
1. The Dialog Manager plugin is built around the DialogWidget class. Any time you want to start a new conversation create an instance and provide the line id for the first line that should be shown.
2. The DialogWidget class includes a delegate, OnConversationCompleted, that can be used to determine when the conversation is completed
3. Be sure that the DialogDataTable and CharacterInfoDataTable property defaults are set in the DialogWidget class, otherwise the lookup function will not work.

## Customizing the dialog system
* DialogCharacterInfo: struct that provides info about each speaker character
* DialogCharacterNames: enum that specifies character names
* DialogEntry: struct that provides info about the specific dialog line
* DT_CharacterInfo: used to customize the speaker characters
* DT_Dialog: data table that stores all of the lines of dialog
* WBP_DialogWidget: handles the dialog info lookup and displaying all of the line details. This class, along with WBP_DialogPlayerResponse can be customized to fit your game style.

## Demo Project
[UE5 Inventory/Dialog Manager Plugin Example](https://github.com/dtb1996/UE5-Inventory-Manager-Example)

## Support
[bitgamingstudio@gmail.com](mailto:bitgamingstudio@gmail.com)

## Attributions
Example dialog audio clips created with [ElevenLabs](https://elevenlabs.io/) - not to be used commercially

Character portraits designed by [Freepik](www.freepik.com)
