#!/usr/bin/node
// Print characters name

const request = require('request');
const url = `https://swapi-api.hbtn.io/api/films/${process.argv[2]}`;
request(url, async function (error, response, body) {
  if (error) {
    console.error(error); // Print the error if one occurred
  } else {
    for (const person of JSON.parse(body).characters) {
      await new Promise(function (resolve, reject) {
        request(person, function (error2, response2, body2) {
          if (error2) {
            console.error(error2); // Print the error if one occurred
          } else {
            console.log(JSON.parse(body2).name);
          }
          resolve();
        });
      });
    }
  }
});
