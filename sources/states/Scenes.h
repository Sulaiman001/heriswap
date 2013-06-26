/*
    This file is part of RecursiveRunner.

    @author Soupe au Caillou - Pierre-Eric Pelloux-Prayer
    @author Soupe au Caillou - Gautier Pelloux-Prayer

    RecursiveRunner is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, version 3.

    RecursiveRunner is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with RecursiveRunner.  If not, see <http://www.gnu.org/licenses/>.
*/
#pragma once

class HeriswapGame;

namespace FadingType {
    enum Enum {
        FadeIn,
        FadeOut
    };
}

namespace Scene {
    enum Enum {
        Ads,
        AdsToBlackState,
        BlackToModeMenu,
        BlackToSpawn,
        CountDown,
        Delete,
        ElitePopup,
        EndMenu,
        ExitState,
        Fall,
        GameToBlack,
        Help,
        LevelChanged,
        Logo,
        MainMenu,
        ModeMenu,
        ModeMenuToBlackState,
        Pause,
        RateIt,
        // ScoreBoard,
        Spawn,
        // Unpause,
        UserInput,
    };

#define DECLARE_SCENE_HANDLER_FACTORY(name) \
    StateHandler<Scene::Enum>* Create##name##SceneHandler(HeriswapGame* game);



    DECLARE_SCENE_HANDLER_FACTORY(Ads)
    DECLARE_SCENE_HANDLER_FACTORY(BlackToModeMenu)
    DECLARE_SCENE_HANDLER_FACTORY(CountDown)
    DECLARE_SCENE_HANDLER_FACTORY(Delete)
    DECLARE_SCENE_HANDLER_FACTORY(ElitePopup)
    DECLARE_SCENE_HANDLER_FACTORY(EndMenu)
    DECLARE_SCENE_HANDLER_FACTORY(ExitState)
    DECLARE_SCENE_HANDLER_FACTORY(Fall)
    DECLARE_SCENE_HANDLER_FACTORY(Help)
    DECLARE_SCENE_HANDLER_FACTORY(LevelChanged)
    DECLARE_SCENE_HANDLER_FACTORY(Logo)
    DECLARE_SCENE_HANDLER_FACTORY(MainMenu)
    DECLARE_SCENE_HANDLER_FACTORY(ModeMenu)
    DECLARE_SCENE_HANDLER_FACTORY(Pause)
    DECLARE_SCENE_HANDLER_FACTORY(RateIt)
    DECLARE_SCENE_HANDLER_FACTORY(ScoreBoard)
    DECLARE_SCENE_HANDLER_FACTORY(Spawn)
    DECLARE_SCENE_HANDLER_FACTORY(Unpause)
    DECLARE_SCENE_HANDLER_FACTORY(UserInput)

    // Declare a unique StateHandler, for all Fade scenes
    StateHandler<Scene::Enum>* CreateFadeSceneHandler(
        HeriswapGame* game,
        FadingType::Enum type,
        float duration,
        Scene::Enum nextState);
}
