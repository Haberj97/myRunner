#include "game_loop.h"

void game_loop(App *app, Stage *stage, long* then, float *remainder){
    while(1){
        prepare_scene(app);
        input_handler(app, stage);
        logic(app, stage);
        draw(app, stage);
        present_scene(app);
        cap_frame_rate(then, remainder);   
    }
}
