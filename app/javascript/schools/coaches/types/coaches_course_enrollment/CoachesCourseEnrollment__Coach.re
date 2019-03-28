type t = {
  id: int,
  name: string,
  imageUrl: string,
  email: string,
  title: string,
};

let name = t => t.name;

let id = t => t.id;

let email = t => t.email;

let imageUrl = t => t.imageUrl;

let title = t => t.title;

let decode = json =>
  Json.Decode.{
    name: json |> field("name", string),
    id: json |> field("id", int),
    imageUrl: json |> field("imageUrl", string),
    email: json |> field("email", string),
    title: json |> field("title", string),
  };

let create =
    (
      id,
      name,
      imageUrl,
      email,
      title,
    ) => {
  id,
  name,
  imageUrl,
  email,
  title,
};

let updateList = (coaches, coach) => {
  let oldList = coaches |> List.filter(t => t.id !== coach.id);
  oldList
  |> List.rev
  |> List.append([coach])
  |> List.rev
  |> List.sort((x, y) => x.id - y.id);
};