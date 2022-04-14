#!/usr/bin/node
/* a script that prints all characters
    of a Star Wars movie */
const request = require('request');
const process = require('process');
const Id = process.argv[2];
const url = `https://swapi.dev/api/films/${Id}/`;
request.get(url, async (_error, response, body) => {
  for (const character of JSON.parse(body).characters) {
    const people = await new Promise((resolve, reject) => {
      request(character, (error, response, body) => {
        if (error) {
          reject(error);
        } else {
          resolve(JSON.parse(body).name);
        }
      });
    });
    console.log(people);
  }
});
