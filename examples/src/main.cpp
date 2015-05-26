#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "NLTemplate.h"


using namespace std;
using namespace NL::Template;



static void createSimpleHTML() {

    std::cout << "============== create /tmp/simple-example.html ===================" << std::endl;
    std::vector<std::string>  titles;
    titles.push_back("Chico");
    titles.push_back("Harpo");
    titles.push_back("Groucho");
    std::vector<std::string>  details;
    details.push_back("Red");
    details.push_back("Green");
    details.push_back("Blue");

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
    const int repeatCount = 5;
    std::vector<std::string>  year;
    year.push_back("2010");
    year.push_back("2011");
    year.push_back("2012");
    year.push_back("2013");
    year.push_back("2014");
    std::vector<std::string>  administrationValuse;
    administrationValuse.push_back("50");
    administrationValuse.push_back("45");
    administrationValuse.push_back("55");
    administrationValuse.push_back("60");
    administrationValuse.push_back("50");
    std::vector<std::string>  serviceValuse;
    serviceValuse.push_back("70");
    serviceValuse.push_back("85");
    serviceValuse.push_back("59");
    serviceValuse.push_back("65");
    serviceValuse.push_back("70");
    std::vector<std::string>  developmentValuse;
    developmentValuse.push_back("60");
    developmentValuse.push_back("65");
    developmentValuse.push_back("69");
    developmentValuse.push_back("65");
    developmentValuse.push_back("70");

    std::cout << "============== create /tmp/plot-example.tex ===================" << std::endl;
    LoaderFile loader;

    Template t( loader );
    t.load( "view/simple-plot.templat.tex" );      // Load & parse the main template and its dependencies.
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

    std::ofstream teXfile ("/tmp/plot-example.tex",std::ofstream::binary);
    t.render( teXfile );
    teXfile.close();

}

static void createPlotHTML() {

    std::cout << "============== create /tmp/plot-example.html ===================" << std::endl;
    // This Part using a google lib
    // https://google-developers.appspot.com/chart/

    const int repeatCount = 5;
    std::vector<std::string>  year;
    year.push_back("2010");
    year.push_back("2011");
    year.push_back("2012");
    year.push_back("2013");
    year.push_back("2014");
    std::vector<std::string>  administrationValuse;
    administrationValuse.push_back("50");
    administrationValuse.push_back("45");
    administrationValuse.push_back("55");
    administrationValuse.push_back("60");
    administrationValuse.push_back("50");
    std::vector<std::string>  serviceValuse;
    serviceValuse.push_back("70");
    serviceValuse.push_back("85");
    serviceValuse.push_back("59");
    serviceValuse.push_back("65");
    serviceValuse.push_back("70");
    std::vector<std::string>  developmentValuse;
    developmentValuse.push_back("60");
    developmentValuse.push_back("65");
    developmentValuse.push_back("69");
    developmentValuse.push_back("65");
    developmentValuse.push_back("70");
    LoaderFile loader;

    Template t( loader );
    t.load( "view/simple-plot.templat.html" );      // Load & parse the main template and its dependencies.
    t.set( "factory", "Muster GmbH" );    // Set a top-level variable
    t.set( "valueadmin", administrationValuse[ 2 ] );
    t.set( "valueservice", serviceValuse[ 2 ] );
    t.set( "valuedev", developmentValuse[ 2 ] );


    t.block( "plotdata" ).repeat( repeatCount );
    for ( int i2=0; i2 < repeatCount; i2++ ) {
        t.block( "plotdata" )[ i2 ].set( "valueyear", year[ i2 ] );
        t.block( "plotdata" )[ i2 ].set( "valueadmin", administrationValuse[ i2 ] );
        t.block( "plotdata" )[ i2 ].set( "valueservice", serviceValuse[ i2 ] );
        t.block( "plotdata" )[ i2 ].set( "valuedev", developmentValuse[ i2 ] );
        std::cout << i2 << std::endl;
        if ( i2 == ( repeatCount - 1 ) ) {
            t.block( "plotdata" )[ i2 ].set( "seperator", "" );
        }else{
            t.block( "plotdata" )[ i2 ].set( "seperator", "," );
            std::cout << "kommer" << std::endl;
        }
    }

    t.block( "datatab" ).repeat( repeatCount );
    for ( int i=0; i < repeatCount; i++ ) {
        t.block( "datatab" )[ i ].set( "year", year[ i ] );
        t.block( "datatab" )[ i ].set( "valueadmin", administrationValuse[ i ] );
        t.block( "datatab" )[ i ].set( "valueservice", serviceValuse[ i ] );
        t.block( "datatab" )[ i ].set( "valuedev", developmentValuse[ i ] );
    }

    std::ofstream htmlFile ("/tmp/plot-example.html",std::ofstream::binary);
    t.render( htmlFile );
    htmlFile.close();


}

int main(int, char *[] ) {
    createSimpleHTML();
    createTeX();
    createPlotHTML();


    return 0;
}
