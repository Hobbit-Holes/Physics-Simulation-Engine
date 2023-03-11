#include "MorgulEngine.hh"
#include "imgui/imgui.h"
#include "imgui/imgui_internal.h"
#include "imgui/imstb_rectpack.h"
#include "imgui/imstb_textedit.h"
#include "imgui/imstb_truetype.h"
#include "imgui/imgui_impl_sdl2.h"
#include "imgui/imgui_impl_sdlrenderer.h"

int main(int argc, char *args[]) {
    MorgulEngine engine = MorgulEngine(800, 800);

    while(engine.NextFrame()) {
        engine.Update();

        //Start the Dear ImGui frame
        ImGui_ImplSDLRenderer_NewFrame();
        ImGui_ImplSDL2_NewFrame();
        ImGui::NewFrame();

        //Debug window
        ImGuiWindowFlags windowFlags = ImGuiWindowFlags_NoDecoration | ImGuiWindowFlags_AlwaysAutoResize | ImGuiWindowFlags_NoNav;
        ImGui::SetNextWindowPos(ImVec2(10, 10), ImGuiCond_Always, ImVec2(0,0));
        ImGui::SetNextWindowBgAlpha(0.9f);
        if(ImGui::Begin("Debug", NULL, windowFlags)) {
            ImGui::Text("Mouse coordinates (x=%.1f, y=%.1f)", ImGui::GetIO().MousePos.x, ImGui::GetIO().MousePos.y);
            ImGui::Spacing();
            ImGui::Text("Frame time %.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);
            ImGui::Spacing();
        } 

        //Close Dear ImGui frame
        ImGui::End();
        ImGui::Render();
        ImGui_ImplSDLRenderer_RenderDrawData(ImGui::GetDrawData());

        engine.Render();

    }

    return 0;
}