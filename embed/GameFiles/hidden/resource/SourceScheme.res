///////////////////////////////////////////////////////////
// Tracker scheme resource file
//
// sections:
//		Colors		- all the colors used by the scheme
//		BaseSettings	- contains settings for app to use to draw controls
//		Fonts			- list of all the fonts used by app
//		Borders		- description of all the borders
//
///////////////////////////////////////////////////////////
Scheme
{
	//////////////////////// COLORS ///////////////////////////
	// color details
	// this is a list of all the colors used by the scheme
	Colors
	{
		// base colors
		"White"			"255 255 255 255"
		"DullWhite"			"255 255 255 200"
		"HS_DarkRed"		"35 0 0 200"
		"HS_DarkRed_Disabled"	"35 0 0 64"
		"HS_DarkGrey"		"17 17 17 200"
		"HS_DarkGrey_Disabled"	"17 17 17 64"
		"HS_LightGrey"		"51 51 51 200"
		"HS_LightGrey_Disabled"	"51 51 51 64"
		"TransparentBlack"	"0 0 0 64"
		"Black"			"0 0 0 255"

		"Blank"			"0 0 0 0"
	}

	///////////////////// BASE SETTINGS ////////////////////////
	//
	// default settings for all panels
	// controls use these to determine their settings
	BaseSettings
	{
		// vgui_controls color specifications
		Border.Bright		"HS_LightGrey"	// lit side of control
		Border.Dark			"HS_LightGrey"	// unlit side of control
		Border.Selection		"0 0 0 180"		// the additional border color for displaying the default/selected button

		Button.TextColor			"White"
		Button.BgColor			"HS_DarkGrey"
		Button.ArmedTextColor		"DullWhite"
		Button.ArmedBgColor		"HS_LightGrey"
		Button.DepressedTextColor	"White"
		Button.DepressedBgColor		"Blank"
		Button.FocusBorderColor		"TransparentBlack"
		
		CheckButton.TextColor		"White"
		CheckButton.SelectedTextColor	"DullWhite"
		CheckButton.BgColor		"TransparentBlack"
		CheckButton.Border1  		"Border.Dark" 	// the left checkbutton border
		CheckButton.Border2  		"Border.Bright"	// the right checkbutton border
		CheckButton.Check			"White"		// color of the check itself

		ComboBoxButton.ArrowColor	 "White"
		ComboBoxButton.ArmedArrowColor "DullWhite"
		ComboBoxButton.BgColor		 "17 17 17 64"
		ComboBoxButton.DisabledBgColor "Blank"

		Frame.TitleTextInsetX			8
		Frame.ClientInsetX			4
		Frame.ClientInsetY			3
		Frame.BgColor				"HS_DarkGrey"
		Frame.OutOfFocusBgColor			"HS_DarkGrey_Disabled"
		Frame.FocusTransitionEffectTime	"0.2"	// time it takes for a window to fade in/out on focus/out of focus
		Frame.TransitionEffectTime		"0.3"	// time it takes for a window to fade in/out on open/close
		Frame.AutoSnapRange			"0"
		FrameGrip.Color1				"220 220 220 128"
		FrameGrip.Color2				"32 32 32 128"
		FrameTitleButton.FgColor		"DullWhite"
		FrameTitleButton.BgColor		"HS_DarkGrey"
		FrameTitleButton.DisabledFgColor	"51 51 51 64"
		FrameTitleButton.DisabledBgColor	"Blank"
		FrameSystemButton.FgColor		"Blank"
		FrameSystemButton.BgColor		"Blank"
		FrameSystemButton.Icon			""
		FrameSystemButton.DisabledIcon	""
		FrameTitleBar.Font			"UIBold"
		FrameTitleBar.TextColor			"White"
		FrameTitleBar.BgColor			"HS_DarkRed"
		FrameTitleBar.DisabledTextColor	"HS_LightGrey_Disabled"
		FrameTitleBar.DisabledBgColor		"HS_DarkRed_Disabled"

		GraphPanel.FgColor			"White"
		GraphPanel.BgColor			"TransparentBlack"

		Label.TextDullColor			"DullWhite"
		Label.TextColor				"White"
		Label.TextBrightColor			"White"
		Label.SelectedTextColor			"White"
		Label.BgColor				"Blank"
		Label.DisabledFgColor1			"117 117 117 128"
		Label.DisabledFgColor2			"30 30 30 128"

		ListPanel.TextColor			"White"
		ListPanel.TextBgColor			"Blank"
		ListPanel.BgColor				"HS_DarkGrey"
		ListPanel.SelectedTextColor		"DullWhite"
		ListPanel.SelectedBgColor		"HS_DarkRed"
		ListPanel.SelectedOutOfFocusBgColor	"HS_DarkRed_Disabled"
		ListPanel.EmptyListInfoTextColor	"HS_LightGrey"

		Menu.TextColor				"White"
		Menu.BgColor				"51 51 51 64"
		Menu.ArmedTextColor			"DullWhite"
		Menu.ArmedBgColor				"HS_DarkRed"
		Menu.TextInset				"6"

		Panel.FgColor				"White"
		Panel.BgColor				"Blank"

		ProgressBar.FgColor			"DullWhite"
		ProgressBar.BgColor			"TransparentBlack"

		PropertySheet.TextColor			"White"
		PropertySheet.SelectedTextColor	"DullWhite"
		PropertySheet.TransitionEffectTime	"0.25"	// time to change from one tab to another

		RadioButton.TextColor			"White"
		RadioButton.SelectedTextColor	      "DullWhite"

		RichText.TextColor			"White"
		RichText.BgColor				"TransparentBlack"
		RichText.SelectedTextColor		"DullWhite"
		RichText.SelectedBgColor		"HS_DarkRed"

		ScrollBar.Wide				16

		ScrollBarButton.FgColor			"White"
		ScrollBarButton.BgColor			"Blank"
		ScrollBarButton.ArmedFgColor		"DullWhite"
		ScrollBarButton.ArmedBgColor		"Blank"
		ScrollBarButton.DepressedFgColor	"White"
		ScrollBarButton.DepressedBgColor	"Blank"

		ScrollBarSlider.FgColor			"HS_LightGrey" // nob color
		ScrollBarSlider.BgColor			"HS_DarkGrey"	// slider background color

		SectionedListPanel.HeaderTextColor	"White"
		SectionedListPanel.HeaderBgColor	"Blank"
		SectionedListPanel.DividerColor	"HS_LightGrey"
		SectionedListPanel.TextColor		"White"
		SectionedListPanel.BrightTextColor	"White"
		SectionedListPanel.BgColor		"TransparentBlack"
		SectionedListPanel.SelectedTextColor	"DullWhite"
		SectionedListPanel.SelectedBgColor		"HS_DarkRed"
		SectionedListPanel.OutOfFocusSelectedTextColor	"HS_LightGrey_Disabled"
		SectionedListPanel.OutOfFocusSelectedBgColor   "HS_DarkRed_Disabled"

		Slider.NobColor			"HS_LightGrey"
		Slider.TextColor			"DullWhite"
		Slider.TrackColor			"31 31 31 255"
		Slider.DisabledTextColor1	"HS_LightGrey_Disabled"
		Slider.DisabledTextColor2	"51 51 51 16"

		TextEntry.TextColor		"White"
		TextEntry.BgColor			"TransparentBlack"
		TextEntry.CursorColor		"White"
		TextEntry.DisabledTextColor	"HS_LightGrey"
		TextEntry.DisabledBgColor	"0 0 0 64"
		TextEntry.SelectedTextColor	"DullWhite"
		TextEntry.SelectedBgColor	"HS_DarkRed"
		TextEntry.OutOfFocusSelectedBgColor	"HS_LightGrey"
		TextEntry.FocusEdgeColor	"0 0 0 180"

		ToggleButton.SelectedTextColor "DullWhite"

		Tooltip.TextColor			"White"
		Tooltip.BgColor			"HS_DarkGrey"

		TreeView.BgColor			"TransparentBlack"

		WizardSubPanel.BgColor		"Blank"

		// scheme-specific colors
		MainMenu.TextColor		"DullWhite"
		MainMenu.ArmedTextColor		"White"
		MainMenu.DepressedTextColor	"180 180 80 255"
		MainMenu.MenuItemHeight		"24"
		MainMenu.Inset			"24"
		MainMenu.Backdrop			"0 0 0 156"

		Console.TextColor			"White"
		Console.DevTextColor		"175 32 32 200"

		NewGame.TextColor			"White"
		NewGame.FillColor			"0 0 0 255"
		NewGame.SelectionColor		"HS_DarkRed"
		NewGame.DisabledColor		"HS_LightGrey_Disbaled"
	}

	//
	//////////////////////// FONTS /////////////////////////////
	//
	// describes all the fonts
	Fonts
	{
		// fonts are used in order that they are listed
		// fonts listed later in the order will only be used if they fulfill a range not already filled
		// if a font fails to load then the subsequent fonts will replace
		// fonts are used in order that they are listed
		"DebugFixed"
		{
			"1"
			{
				"name"		"Verdana"
				"tall"		"10"
				"weight"	"500"
				"antialias" "1"
			}
		}
		// fonts are used in order that they are listed
		"DebugFixedSmall"
		{
			"1"
			{
				"name"		"Verdana"
				"tall"		"7"
				"weight"	"500"
				"antialias" "1"
			}
		}
		"DefaultFixedOutline"
		{
			"1"
			{
				"name"		"Lucida Console"
				"tall"		"10"
				"weight"	"0"
				"outline"	"1"
			}
		}
		"Default"
		{
			"1"
			{
				"name"		"OratorStd"
				"tall"		"16"
				"weight"	"500"
				"antialias" "1"
			}
		}
		"DefaultBold"
		{
			"1"
			{
				"name"		"OratorStd"
				"tall"		"16"
				"weight"	"1000"
				"antialias" "1"
			}
		}
		"DefaultUnderline"
		{
			"1"
			{
				"name"		"OratorStd"
				"tall"		"16"
				"weight"	"500"
				"underline" "1"
				"antialias" "1"
			}
		}
		"DefaultSmall"
		{
			"1"
			{
				"name"		"Verdana"
				"tall"		"12"
				"weight"	"0"
			}
		}
		"DefaultSmallDropShadow"
		{
			"1"
			{
				"name"		"Verdana"  
				"tall"		"13"
				"weight"	"0"
				"dropshadow" "1"
			}
		}
		"DefaultVerySmall"
		{
			"1"
			{
				"name"		"Verdana"
				"tall"		"12"
				"weight"	"0"
			}
		}

		"DefaultLarge"
		{
			"1"
			{
				"name"		"OratorStd"
				"tall"		"18"
				"weight"	"0"
				"antialias" "1"
			}
		}
		"UiBold"
		{
			"1"
			{
				"name"		"OratorStd"
				"tall"		"16"
				"weight"		"400"
				"antialias" "1"


			}
		}
		"MenuLarge"
		{
			"1"
			{
				"name"		"OratorStd"
				"tall"		"16"
				"weight"	"0"
				"antialias" "1"
			}
		}

		"ConsoleText"
		{
			"1"
			{
				"name"		"Lucida Console"
				"tall"		"10"
				"weight"	"500"
			}
		}

		// this is the symbol font
		"Marlett"
		{
			"1"
			{
				"name"		"Marlett"
				"tall"		"14"
				"weight"	"0"
				"symbol"	"1"
			}
		}

		"Trebuchet24"
		{
			"1"
			{
				"name"		"OratorStd"
				"tall"		"24"
				"weight"	"900"
				"antialias" "1"
			}
		}


		"Trebuchet20"
		{
			"1"
			{
				"name"		"OratorStd"
				"tall"		"20"
				"weight"	"900"
				"antialias" "1"
			}
		}

		"Trebuchet18"
		{
			"1"
			{
				"name"		"OratorStd"
				"tall"		"18"
				"weight"	"900"
				"antialias" "1"
			}
		}

		// HUD numbers
		// We use multiple fonts to 'pulse' them in the HUD, hence the need for many of near size
		"HUDNumber"
		{
			"1"
			{
				"name"		"OratorStd"
				"tall"		"40"
				"weight"	"900"
				"antialias" "1"
			}
		}
		"HUDNumber1"
		{
			"1"
			{
				"name"		"OratorStd"
				"tall"		"41"
				"weight"	"900"
				"antialias" "1"
			}
		}
		"HUDNumber2"
		{
			"1"
			{
				"name"		"OratorStd"
				"tall"		"42"
				"weight"	"900"
				"antialias" "1"
			}
		}
		"HUDNumber3"
		{
			"1"
			{
				"name"		"OratorStd"
				"tall"		"43"
				"weight"	"900"
				"antialias" "1"
			}
		}
		"HUDNumber4"
		{
			"1"
			{
				"name"		"OratorStd"
				"tall"		"44"
				"weight"	"900"
				"antialias" "1"
			}
		}
		"HUDNumber5"
		{
			"1"
			{
				"name"		"OratorStd"
				"tall"		"45"
				"weight"	"900"
				"antialias" "1"
			}
		}
		"DefaultFixed"
		{
			"1"
			{
				"name"		"Lucida Console"
				"tall"		"10"
				"weight"	"0"
			}
//			"1"
//			{
//				"name"		"FixedSys"
//				"tall"		"20"
//				"weight"	"0"
//			}
		}

		"DefaultFixedDropShadow"
		{
			"1"
			{
				"name"		"Lucida Console"
				"tall"		"10"
				"weight"	"0"
				"dropshadow" "1"
			}
//			"1"
//			{
//				"name"		"FixedSys"
//				"tall"		"20"
//				"weight"	"0"
//			}
		}

		"CloseCaption_Normal"
		{
			"1"
			{
				"name"		"OratorStd"
				"tall"		"16"
				"weight"	"500"
				"antialias" "1"
			}
		}
		"CloseCaption_Italic"
		{
			"1"
			{
				"name"		"OratorStd"
				"tall"		"16"
				"weight"	"500"
				"italic"	"1"
				"antialias" "1"
			}
		}
		"CloseCaption_Bold"
		{
			"1"
			{
				"name"		"OratorStd"
				"tall"		"16"
				"weight"	"900"
				"antialias" "1"
			}
		}
		"CloseCaption_BoldItalic"
		{
			"1"
			{
				"name"		"OratorStd"
				"tall"		"16"
				"weight"	"900"
				"italic"	"1"
				"antialias" "1"
			}
		}

		TitleFont
		{
			"1"
			{
				"name"		"OratorStd"
				"tall"		"14"
				"weight"	"400"
				"antialias"	"1"
				"additive"  "1"
				"custom"	"1"
			}
		}

		TitleFont2
		{
			"1"
			{
				"name"		"OratorStd"
				"tall"		"14"
				"weight"	"400"
				"antialias"	"1"
				"additive"  "1"
				"custom"	"1"
			}
		}
	}

	//
	//////////////////// BORDERS //////////////////////////////
	//
	// describes all the border types
	Borders
	{
		BaseBorder		DepressedBorder
		ButtonBorder	RaisedBorder
		ComboBoxBorder	DepressedBorder
		MenuBorder		RaisedBorder
		BrowserBorder	DepressedBorder
		PropertySheetBorder	RaisedBorder

		FrameBorder
		{
			// rounded corners for frames
			"backgroundtype" "3"
		}

		DepressedBorder
		{
			"inset" "0 0 1 1"
			Left
			{
				"1"
				{
					"color" "Border.Dark"
					"offset" "0 1"
				}
			}

			Right
			{
				"1"
				{
					"color" "Border.Bright"
					"offset" "1 0"
				}
			}

			Top
			{
				"1"
				{
					"color" "Border.Dark"
					"offset" "0 0"
				}
			}

			Bottom
			{
				"1"
				{
					"color" "Border.Bright"
					"offset" "0 0"
				}
			}
		}
		RaisedBorder
		{
			"inset" "0 0 1 1"
			Left
			{
				"1"
				{
					"color" "Border.Bright"
					"offset" "0 1"
				}
			}

			Right
			{
				"1"
				{
					"color" "Border.Dark"
					"offset" "0 0"
				}
			}

			Top
			{
				"1"
				{
					"color" "Border.Bright"
					"offset" "0 1"
				}
			}

			Bottom
			{
				"1"
				{
					"color" "Border.Dark"
					"offset" "0 0"
				}
			}
		}
		
		TitleButtonBorder
		{
			"backgroundtype" "0"
		}

		TitleButtonDisabledBorder
		{
			"backgroundtype" "0"
		}

		TitleButtonDepressedBorder
		{
			"backgroundtype" "0"
		}

		ScrollBarButtonBorder
		{
			"inset" "2 2 0 0"
			Left
			{
				"1"
				{
					"color" "Border.Bright"
					"offset" "0 1"
				}
			}

			Right
			{
				"1"
				{
					"color" "Border.Dark"
					"offset" "1 0"
				}
			}

			Top
			{
				"1"
				{
					"color" "Border.Bright"
					"offset" "0 0"
				}
			}

			Bottom
			{
				"1"
				{
					"color" "Border.Dark"
					"offset" "0 0"
				}
			}
		}
		
		ScrollBarButtonDepressedBorder
		{
			"inset" "2 2 0 0"
			Left
			{
				"1"
				{
					"color" "Border.Dark"
					"offset" "0 1"
				}
			}

			Right
			{
				"1"
				{
					"color" "Border.Bright"
					"offset" "1 0"
				}
			}

			Top
			{
				"1"
				{
					"color" "Border.Dark"
					"offset" "0 0"
				}
			}

			Bottom
			{
				"1"
				{
					"color" "Border.Bright"
					"offset" "0 0"
				}
			}
		}

		TabBorder
		{
			"inset" "0 0 1 1"
			Left
			{
				"1"
				{
					"color" "Border.Bright"
					"offset" "0 1"
				}
			}

			Right
			{
				"1"
				{
					"color" "Border.Dark"
					"offset" "1 0"
				}
			}

			Top
			{
				"1"
				{
					"color" "Border.Bright"
					"offset" "0 0"
				}
			}

		}

		TabActiveBorder
		{
			"inset" "0 0 1 0"
			Left
			{
				"1"
				{
					"color" "Border.Bright"
					"offset" "0 0"
				}
			}

			Right
			{
				"1"
				{
					"color" "Border.Dark"
					"offset" "1 0"
				}
			}

			Top
			{
				"1"
				{
					"color" "Border.Bright"
					"offset" "0 0"
				}
			}

		}


		ToolTipBorder
		{
			"inset" "0 0 1 0"
			Left
			{
				"1"
				{
					"color" "Border.Dark"
					"offset" "0 0"
				}
			}

			Right
			{
				"1"
				{
					"color" "Border.Dark"
					"offset" "1 0"
				}
			}

			Top
			{
				"1"
				{
					"color" "Border.Dark"
					"offset" "0 0"
				}
			}

			Bottom
			{
				"1"
				{
					"color" "Border.Dark"
					"offset" "0 0"
				}
			}
		}

		// this is the border used for default buttons (the button that gets pressed when you hit enter)
		ButtonKeyFocusBorder
		{
			"inset" "0 0 1 1"
			Left
			{
				"1"
				{
					"color" "Border.Selection"
					"offset" "0 0"
				}
				"2"
				{
					"color" "Border.Bright"
					"offset" "0 1"
				}
			}
			Top
			{
				"1"
				{
					"color" "Border.Selection"
					"offset" "0 0"
				}
				"2"
				{
					"color" "Border.Bright"
					"offset" "1 0"
				}
			}
			Right
			{
				"1"
				{
					"color" "Border.Selection"
					"offset" "0 0"
				}
				"2"
				{
					"color" "Border.Dark"
					"offset" "1 0"
				}
			}
			Bottom
			{
				"1"
				{
					"color" "Border.Selection"
					"offset" "0 0"
				}
				"2"
				{
					"color" "Border.Dark"
					"offset" "0 0"
				}
			}
		}

		ButtonDepressedBorder
		{
			"inset" "2 1 1 1"
			Left
			{
				"1"
				{
					"color" "Border.Dark"
					"offset" "0 1"
				}
			}

			Right
			{
				"1"
				{
					"color" "Border.Bright"
					"offset" "1 0"
				}
			}

			Top
			{
				"1"
				{
					"color" "Border.Dark"
					"offset" "0 0"
				}
			}

			Bottom
			{
				"1"
				{
					"color" "Border.Bright"
					"offset" "0 0"
				}
			}
		}
	}

	//////////////////////// CUSTOM FONT FILES /////////////////////////////
	//
	// specifies all the custom (non-system) font files that need to be loaded to service the above described fonts
	CustomFontFiles
	{
		"1"		"resource/HALFLIFE2.ttf"
		"2"		"resource/OratorStd.ttf"
		"3"		"resource/OratorStd.ttf"
	}
}

