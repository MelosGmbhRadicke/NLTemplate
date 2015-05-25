#include <iostream>
#include <fstream>
#include <string>

#include "NLTemplate.h"


using namespace std;
using namespace NL::Template;



static void createSimpleHTML() {

    std::cout << "============== create /tmp/simple-example.html ===================" << std::endl;
    const char *titles[ 3 ] = { "Chico", "Harpo", "Groucho" };
    const char *details[ 3 ] = { "Red", "Green", "Blue" };

    LoaderFile loader; // Let's use the default loader that loads files from disk.

    Template t( loader );

    t.load( "view/test.txt" );      // Load & parse the main template and its dependencies.
    t.set( "text", "Hello, world" );    // Set a top-level variable
    t.block( "items" ).repeat( 3 );     // We need to know in advance that the "items" block will repeat 3 times.

    // Let's fill in the data for the repeated block.
    for ( int i=0; i < 3; i++ ) {
        // Set title and text by accessing the variable directly
        t.block( "items" )[ i ].set( "title", titles[ i ] );
        t.block( "items" )[ i ].set( "text", "Lorem Ipsum" );

        // We can get a shortcut reference to a nested block
        Block & block = t.block( "items" )[ i ].block( "detailblock" );
        block.set( "detail", details[ i ] );

        // Disable this block for the first item in the list. Can be useful for opening/closing HTML tables etc.
        if ( i==0 ) {
            block.disable();
        }
    }

    std::ofstream htmlFile ("/tmp/simple-example.html",std::ofstream::binary);
    t.render( htmlFile ); // Render the template with the variables we've set above
    htmlFile.close();

}

static void createTeX() {
    int repeatCount = 5;
    const char *year[ repeatCount ] = { "2010", "2011", "2012", "2013", "2014" };
    const char *administrationValuse[ repeatCount ] = { "50", "45", "55", "60", "50" };
    const char *serviceValuse[ repeatCount ] = { "70", "85", "59", "65", "70" };
    const char *developmentValuse[ repeatCount ] = { "60", "65", "69", "65", "70" };

    std::cout << "============== create /tmp/plot-example.TeX ===================" << std::endl;
    LoaderFile loader;

    Template t( loader );
    t.load( "view/simple_plot.templat.tex" );      // Load & parse the main template and its dependencies.
    t.set( "factory", "Muster GmbH" );    // Set a top-level variable

    t.block( "administration" ).repeat( repeatCount );
    for ( int i=0; i < repeatCount; i++ ) {
        t.block( "administration" )[ i ].set( "year", year[ i ] );
        t.block( "administration" )[ i ].set( "value", administrationValuse[ i ] );
    }

    t.block( "service" ).repeat( repeatCount );
    for ( int i=0; i < repeatCount; i++ ) {
        t.block( "service" )[ i ].set( "year", year[ i ] );
        t.block( "service" )[ i ].set( "value", serviceValuse[ i ] );
    }

    t.block( "development" ).repeat( repeatCount );
    for ( int i=0; i < repeatCount; i++ ) {
        t.block( "development" )[ i ].set( "year", year[ i ] );
        t.block( "development" )[ i ].set( "value", developmentValuse[ i ] );
    }

    t.block( "average" ).repeat( repeatCount );
    for ( int i=0; i < repeatCount; i++ ) {
        t.block( "average" )[ i ].set( "year", year[ i ] );
        int average = (std::stoi(administrationValuse[ i ]) + std::stoi(serviceValuse[ i ]) + std::stoi(developmentValuse[ i ]) ) / 3;
        t.block( "average" )[ i ].set( "value", std::to_string(average) );
    }

    t.block( "datatab" ).repeat( repeatCount );
    for ( int i=0; i < repeatCount; i++ ) {
        t.block( "datatab" )[ i ].set( "year", year[ i ] );
        t.block( "datatab" )[ i ].set( "valueadmin", administrationValuse[ i ] );
        t.block( "datatab" )[ i ].set( "valueservice", serviceValuse[ i ] );
        t.block( "datatab" )[ i ].set( "valuedev", developmentValuse[ i ] );
    }

    std::ofstream teXfile ("/tmp/plot-example.TeX",std::ofstream::binary);
    t.render( teXfile ); // Render the template with the variables we've set above
    teXfile.close();

}

static void createPlotHTML() {

    std::cout << "============== create /tmp/plot-example.html ===================" << std::endl;
    int repeatCount = 5;
    const char *year[ repeatCount ] = { "2010", "2011", "2012", "2013", "2014" };
    const char *administrationValuse[ repeatCount ] = { "50", "45", "55", "60", "50" };
    const char *serviceValuse[ repeatCount ] = { "70", "85", "59", "65", "70" };
    const char *developmentValuse[ repeatCount ] = { "60", "65", "69", "65", "70" };
    LoaderFile loader;

    Template t( loader );
    t.load( "view/simple_plot.templat.html" );      // Load & parse the main template and its dependencies.
    t.set( "factory", "Muster GmbH" );    // Set a top-level variable
    t.set( "valueadmin", administrationValuse[ 2 ] );
    t.set( "valueservice", serviceValuse[ 2 ] );
    t.set( "valuedev", developmentValuse[ 2 ] );

    std::ofstream htmlFile ("/tmp/plot-example.html",std::ofstream::binary);
    t.render( htmlFile ); // Render the template with the variables we've set above
    htmlFile.close();


}

int main(int, char *[] ) {
    createSimpleHTML();
    createTeX();
    createPlotHTML();


    return 0;
}
