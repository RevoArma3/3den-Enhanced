class Enh_3denRadio
{
	idd = ENH_3DENRADIO;
	movingEnable = true;
	onLoad = "_this spawn Enh_fnc_3denRadio_onLoad";
	onUnload = "_this call Enh_fnc_3denRadio_onUnload"
	class ControlsBackground
	{
		DISABLE_BACKGROUND
		class ButtonBackground: Enh_Background
		{
			x = 0.703437 * safezoneW + safezoneX;
			y = 0.71 * safezoneH + safezoneY;
			w = 0.164062 * safezoneW;
			h = 0.14 * safezoneH;
		};
		class SonglistBackground: Enh_Background
		{
			x = 0.1325 * safezoneW + safezoneX;
			y = 0.178 * safezoneH + safezoneY;
			w = 0.564375 * safezoneW;
			h = 0.672 * safezoneH;
		};
	};
	class Controls
	{
		class ToggleRadio: Enh_Button
		{
			idc = 2300;
			x = 0.71 * safezoneW + safezoneX;
			y = 0.724 * safezoneH + safezoneY;
			w = 0.0721875 * safezoneW;
			h = 0.028 * safezoneH;
			action = "'BUTTON' call Enh_fnc_3denRadio_toggleRadio";
		};
		class VolumeSlider: Enh_Slider
		{
			idc = 1900;
			x = 0.703437 * safezoneW + safezoneX;
			y = 0.668 * safezoneH + safezoneY;
			w = 0.164062 * safezoneW;
			h = 0.028 * safezoneH;
			onSliderPosChanged = "0 fadeMusic (sliderPosition (_this # 0))";
		};
		class HelpText: Enh_StructuredText
		{
			idc = 2400;
			text = $STR_ENH_3denRadio_help_description;
			x = 0.1325 * safezoneW + safezoneX;
			y = 0.864 * safezoneH + safezoneY;
			w = 0.564375 * safezoneW;
			h = 0.098 * safezoneH;
			onLoad = "_this # 0 ctrlSetFade 1;  _this # 0 ctrlCommit 0;";
		};
		class CurrentSong: Enh_Text
		{
			idc = 2200;
			x = 0.1325 * safezoneW + safezoneX;
			y = 0.822 * safezoneH + safezoneY;
			w = 0.413438 * safezoneW;
			h = 0.028 * safezoneH;
   			colorBackground[] = COLOUR_USER_PRESET;
		};
		class Songlist: Enh_ListBox
		{
			idc = 1500;
			idcLeft = -1;
			idcRight = -1;
			x = 0.1325 * safezoneW + safezoneX;
			y = 0.178 * safezoneH + safezoneY;
			w = 0.564375 * safezoneW;
			h = 0.644 * safezoneH;
			type = CT_LISTNBOX;
			onLBDblClick  = "call Enh_fnc_3denRadio_playMusic";
			onKeyDown = "['ADDSONG',_this select 1] call Enh_fnc_3denRadio_handlePlaylist; _this call Enh_fnc_3denRadio_exportClassname";
		};
		class Playlist: Enh_ListBox
		{
			idc = 2000;
			x = 0.703436 * safezoneW + safezoneX;
			y = 0.178 * safezoneH + safezoneY;
			w = 0.164062 * safezoneW;
			h = 0.476 * safezoneH;
			onLBDblClick  = "call Enh_fnc_3denRadio_playMusic";
			onKeyDown = "['REMOVESONG',_this # 1] call Enh_fnc_3denRadio_handlePlaylist";
		};
		class SearchEdit: Enh_Edit
		{
			idc = 1400;
			x = 0.545937 * safezoneW + safezoneX;
			y = 0.822 * safezoneH + safezoneY;
			w = 0.1312495 * safezoneW;
			h = 0.028 * safezoneH;
			onKeyUp = "call Enh_fnc_3denRadio_searchList;";//onKeyUp to give the control time to update
		};
		class SearchIcon: ctrlStaticPictureKeepAspect
		{
			text = "\a3\3DEN\Data\Displays\Display3DEN\search_start_ca.paa";
			x = 0.6771865 * safezoneW + safezoneX;
			y = 0.822 * safezoneH + safezoneY;
			w = 0.0196875 * safezoneW;
			h = 0.028 * safezoneH;
		};
		class Title_Headline: Enh_Button
		{
			text = $STR_ENH_3denRadio_headline_title;
			x = 0.1325 * safezoneW + safezoneX;
			y = 0.15 * safezoneH + safezoneY;
			w = 0.328125 * safezoneW;
			h = 0.028 * safezoneH;
			action = "'NAME' call Enh_fnc_3denRadio_sortBy";
		};
		class Theme_Headline: Enh_Button
		{
			text = $STR_ENH_3denRadio_headline_theme;
			x = 0.539974 * safezoneW + safezoneX;
			y = 0.15 * safezoneH + safezoneY;
			w = 0.0981375 * safezoneW;
			h = 0.028 * safezoneH;
			action = "'THEME' call Enh_fnc_3denRadio_sortBy";
		};
		class Playlist_Headline: Enh_Text
		{
			text = $STR_ENH_3denRadio_playlist_text;
			x = 0.703437 * safezoneW + safezoneX;
			y = 0.15 * safezoneH + safezoneY;
			w = 0.164062 * safezoneW;
			h = 0.028 * safezoneH;
   			colorBackground[] = COLOUR_USER_PRESET;
		};
		class Duration_Headline: Enh_Button
		{
			text = $STR_ENH_3denRadio_headline_duration;
			x = 0.460625 * safezoneW + safezoneX;
			y = 0.15 * safezoneH + safezoneY;
			w = 0.07975 * safezoneW;
			h = 0.028 * safezoneH;
			action = "'DURATION' call Enh_fnc_3denRadio_sortBy";
		};
		class Mod_Headline: Enh_Text
		{
			text = $STR_ENH_3denRadio_headline_mod;
			x = 0.637812 * safezoneW + safezoneX;
			y = 0.15 * safezoneH + safezoneY;
			w = 0.0590625 * safezoneW;
			h = 0.028 * safezoneH;
			colorBackground[] = COLOUR_USER_PRESET;
		};
		class Close: Enh_Button
		{
			idc = 1;
			text = $STR_ENH_3denRadio_saveAndClose_text;
			x = 0.78875 * safezoneW + safezoneX;
			y = 0.724 * safezoneH + safezoneY;
			w = 0.0721875 * safezoneW;
			h = 0.028 * safezoneH;
		};
		class Export: Enh_Button
		{
			text = $STR_ENH_3denRadio_exportPlaylist_text;
			x = 0.71 * safezoneW + safezoneX;
			y = 0.766 * safezoneH + safezoneY;
			w = 0.0721875 * safezoneW;
			h = 0.028 * safezoneH;
			action = "'EXPORT'call Enh_fnc_3denRadio_handlePlaylist";
		};
		class Import: Enh_Button
		{
			text = $STR_ENH_3denRadio_importPlaylist_text;
			x = 0.78875 * safezoneW + safezoneX;
			y = 0.766 * safezoneH + safezoneY;
			w = 0.0721875 * safezoneW;
			h = 0.028 * safezoneH;
			action = "'IMPORT'call Enh_fnc_3denRadio_handlePlaylist";
		};
		class ClearPlaylist: Enh_Button
		{
			text = $STR_ENH_3denRadio_clearPlaylist_text;
			x = 0.71 * safezoneW + safezoneX;
			y = 0.808 * safezoneH + safezoneY;
			w = 0.0721875 * safezoneW;
			h = 0.028 * safezoneH;
			action = "'CLEAR' call Enh_fnc_3denRadio_handlePlaylist";
		};
		class ToggleHelp: Enh_Button
		{
			text = $STR_ENH_3denRadio_help_text;
			x = 0.78875 * safezoneW + safezoneX;
			y = 0.808 * safezoneH + safezoneY;
			w = 0.0721875 * safezoneW;
			h = 0.028 * safezoneH;
			onButtonClick = "_this call Enh_fnc_3denRadio_toggleHelp";
		};
	};
};