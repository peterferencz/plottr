#include "test_commandSuite.h"


// Requires
// - Expression
// - BasicPlotter / ASCIIPlotter
// - Screen / PlotterScreen / InfoScreen
// - Front
void testCommandSuite() {
    Expression expression(new double[3] {0, 1, 2}, 3);
    Plotter* basicPlotter = new BasicPlotter(expression);
    Plotter* asciiPlotter = new ASCIIPlotter(expression);
    PlotterScreen plotterScreen(expression, basicPlotter);
    InfoScreen infoScreen(expression);
    Front ui(&plotterScreen);
    
    
    TEST(commands, MoveCommand){
        MoveCommand cmd(plotterScreen);
        
        cmd.exec({"0", "0"});
        EXPECT_EQ(0, plotterScreen.getWorldArea().x);
        EXPECT_EQ(0, plotterScreen.getWorldArea().y);

        cmd.exec({"-76", "89723.74"});
        EXPECT_EQ(-76, plotterScreen.getWorldArea().x);
        EXPECT_EQ(89723.74, plotterScreen.getWorldArea().y);

        EXPECT_THROW(cmd.exec({"not a number", "other"}), const std::invalid_argument&);
    } ENDM

    TEST(commands, TUICommand){
        TUICommand cmd;
        
        Console::init();
        bool tui = Console::getTUI();
        
        cmd.exec({});

        EXPECT_EQ(!tui, Console::getTUI());

        Console::destroy();
    } ENDM
    
    TEST(commands, OffsetCommand){
        OffsetCommand cmd(plotterScreen);
        
        cmd.exec({"0", "0"});
        //TODO test exec

        EXPECT_THROW(cmd.exec({"not a number", "other"}), const std::invalid_argument&);
    } ENDM

    TEST(commands, ScaleCommand){
        ScaleCommand cmd(plotterScreen);
        
        cmd.exec({"0", "0"});
        //TODO test exec

        EXPECT_THROW(cmd.exec({"not a number", "other"}), const std::invalid_argument&);
    } ENDM

    TEST(commands, InfoCommand){
        InfoCommand cmd(ui, infoScreen);
        
        cmd.exec({});
        EXPECT_EQ(&ui.getScreen(), &infoScreen);

    } ENDM

    TEST(commands, PlotCommand){
        PlotCommand cmd(ui, plotterScreen, expression);
        
        cmd.exec({});
        EXPECT_EQ(&ui.getScreen(), &plotterScreen);

        EXPECT_THROW(cmd.exec({"not a number", "other"}), const std::invalid_argument&);
        cmd.exec({"5689", "-9898843", "0.3"});
        EXPECT_EQ((size_t) 3, expression.getCoefficients().second);
        EXPECT_EQ(5689, expression.getCoefficients().first[0]);
        EXPECT_EQ(-9898843, expression.getCoefficients().first[1]);
        EXPECT_EQ(0.3, expression.getCoefficients().first[2]);
    } ENDM

    TEST(commands, StyleCommand){
        StyleCommand cmd(plotterScreen, {
            basicPlotter,
            asciiPlotter
        });
        
        cmd.exec({"basic"});
        EXPECT_EQ(plotterScreen.getPlotter(), basicPlotter);
        cmd.exec({"ascii"});
        EXPECT_EQ(plotterScreen.getPlotter(), asciiPlotter);

        EXPECT_THROW(cmd.exec({"invalid"}), const InvalidStyleException&);
    } ENDM


    TEST(commands, OutCommand){
        OutCommand cmd(plotterScreen);
        
        //TODO test
        // cmd.exec({"filename"});
    } ENDM

    TEST(commands, CommandManager){
        // CommandManager manager{
        //     new TUICommand(),
        //     new MoveCommand(plotterScreen),
        //     new OffsetCommand(plotterScreen),
        //     new ScaleCommand(plotterScreen),
        //     new InfoCommand(ui, infoScreen),
        //     new PlotCommand(ui, plotterScreen, expression),
        //     new StyleCommand(plotterScreen, {
        //         basicPlotter,
        //         asciiPlotter
        //     }),
        //     new OutCommand(plotterScreen)
        // };

        
        
        //TODO test
        // cmd.exec({});
    } ENDM
}
