SELECT AVG(energy) AS average_energy FROM songs JOIN artists ON songs.artist_id= artists.id where artists.name = 'Drake';
